#include "../../include/GUI/GameWorld.hpp"
#include "../../include/GUI/GUIWorld.hpp"
#include "../../include/GUI/EditorWorld.hpp"
#include "../../include/Graphics/Utility.h"

#include <imgui.h>
#include <imgui-SFML.h>

namespace most
{
	namespace GUI
	{
		decltype(EditorWorld::maxDistances) EditorWorld::maxDistances{200.1f, 200.1f, -1.0f};

		EditorWorld::EditorWorld()
			: buildInProgress(false), woodSprite(GraphicsWorld::getInstance()->getWoodLowResTexture()), roadSprite(GraphicsWorld::getInstance()->getRoadLowResTexture()), userInteractions(GraphicsWorld::getInstance()->addEventCallback([this](const sf::Event& e) { processEvent(e); }))
		{
			gridGizmo.setRadius(10);
			gridGizmo.setFillColor(sf::Color::Red);
			gridGizmo.setOrigin(10, 10);

			ledgeLeft.setSize(sf::Vector2f(1000, 200));
			ledgeLeft.setOrigin(sf::Vector2f(1000, 100));
			ledgeLeft.setPosition(sf::Vector2f(-250, 200));
			ledgeLeft.setFillColor(sf::Color(94, 235, 52));
			
			ledgeRight.setSize(sf::Vector2f(1000, 200));
			ledgeRight.setOrigin(sf::Vector2f(0, 100));
			ledgeRight.setPosition(sf::Vector2f(250, 200));
			ledgeRight.setFillColor(sf::Color(94, 235, 52));
		}

		EditorWorld::~EditorWorld()
		{
			GraphicsWorld::getInstance()->removeEventCallback(userInteractions);
		}

		void EditorWorld::processEvent(const sf::Event& e)
		{
			sf::Vector2i mousePos;
			sf::Vector2f posOnGrid;

			switch (e.type)
			{
			case sf::Event::MouseButtonReleased:
				if (e.mouseButton.button != sf::Mouse::Button::Left)
				{
					if (e.mouseButton.button == sf::Mouse::Button::Right)
					{
						buildInProgress = false;
						currentElement = ElementType::None;
					}
					return;
				}
				mousePos.x = e.mouseButton.x;
				mousePos.y = e.mouseButton.y;
				posOnGrid = globalPosToGlobalGridPos(GraphicsWorld::getInstance()->mousePositionToWorld(mousePos));
				
				switch (currentElement)
				{
				case ElementType::Beam:
					FALLTHROUGH
				case ElementType::Road:
					if (buildInProgress)
					{
						// Place the beam.
						if (distance(posOnGrid, beginBuildPos) <= maxDistances[((std::underlying_type_t<ElementType>)currentElement) - 1])
						{
							placedBeams.emplace_back(Beam{ buildGizmo, currentElement });
							buildInProgress = false;
						}
					}
					else
					{
						// Remember the beggining position.
						beginBuildPos = posOnGrid;
						buildInProgress = true;
					}
					break;
				case ElementType::Remove:
				{
					const auto globalMousePos = GraphicsWorld::getInstance()->mousePositionToWorld(mousePos);
					const auto end = placedBeams.rend();
					for (auto it = placedBeams.rbegin(); it != end; ++it)
					{
						if (it->visuals.getGlobalBounds().contains(globalMousePos))
						{
							placedBeams.erase(std::next(it).base());
							break;
						}
					}
				}
					break;
				}
				break;
			case sf::Event::MouseMoved:
				mousePos.x = e.mouseMove.x;
				mousePos.y = e.mouseMove.y;
				posOnGrid = globalPosToGlobalGridPos(GraphicsWorld::getInstance()->mousePositionToWorld(mousePos));

				if (buildInProgress)
				{
					if (distance(posOnGrid, beginBuildPos) <= maxDistances[((std::underlying_type_t<ElementType>)currentElement) - 1])
					{
						setBuildGizmoTransform(posOnGrid);
					}
				}
				break;
			default:
				return;
			}

			gridGizmo.setPosition(posOnGrid);
		}

		void EditorWorld::setBuildGizmoTransform(const sf::Vector2f& to)
		{
			const auto vec = to - beginBuildPos;
			const auto length = magnitude(vec);
			if (length <= 0.001f)
			{
				buildGizmo.setSize(sf::Vector2f());
				return;
			}
			const auto normVec = normalize(vec, length);
			const auto cosAngle = clamp(dot(normVec, sf::Vector2f(1, 0)), -1.0f, 1.0f);
			const auto angle = std::copysign(rad2deg(std::acos(cosAngle)), vec.y < 0 ? -1.0f : 1.0f);
			buildGizmo.setRotation(angle);
			buildGizmo.setSize(sf::Vector2f(length, BeamWidth));
			const sf::Vector2f orig(length / 2.0f, BeamWidth / 2.0f);
			buildGizmo.setOrigin(orig);
			buildGizmo.setPosition(sf::Vector2f(beginBuildPos.x + (vec.x / 2.0f), beginBuildPos.y + (vec.y / 2.0f)));
		}

		void EditorWorld::setCurrentElement(const ElementType type)
		{
			using E = ElementType;
			switch (type)
			{
			case E::None:
				FALLTHROUGH
			case E::Remove:
				buildInProgress = false;
				break;
			case E::Beam:
				buildGizmo.setTexture(&GraphicsWorld::getInstance()->getWoodTexture());
				break;
			case E::Road:
				buildGizmo.setTexture(&GraphicsWorld::getInstance()->getRoadTexture());
				break;
			default:
				return;
			}
			currentElement = type;
		}

		sf::Vector2f EditorWorld::globalPosToGlobalGridPos(const sf::Vector2f& pos) const
		{
			return sf::Vector2f(pos.x - std::fmod(pos.x, GridSeparation) + (GridSeparation / 2.0f * std::copysign(1.0f, pos.x)), pos.y - std::fmod(pos.y, GridSeparation) + (GridSeparation / 2.0f * std::copysign(1.0f, pos.y)));
		}

		void EditorWorld::update()
		{
			if (currentElement == ElementType::None)
			{
				if (ImGui::Begin("Toolbox", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					if (ImGui::ImageButton(woodSprite))
					{
						setCurrentElement(ElementType::Beam);
					}
					if (ImGui::ImageButton(roadSprite))
					{
						setCurrentElement(ElementType::Road);
					}
					if (ImGui::Button("Remove tool"))
					{
						setCurrentElement(ElementType::Remove);
					}
					if (ImGui::Button("Play!"))
					{
						// TODO: Change scene, create physics objects, begin simulation.
						GUI::World::getInstance()->setScene(std::make_unique<GUI::GameWorld>());
					}
				}
				ImGui::End();
			}
		}

		void EditorWorld::draw(sf::RenderTarget& rt, sf::RenderStates states) const
		{
			rt.draw(ledgeLeft, states);
			rt.draw(ledgeRight, states);

			for (const auto& x : placedBeams)
			{
				rt.draw(x.visuals, states);
			}

			if (buildInProgress)
			{
				rt.draw(buildGizmo, states);
			}
			switch (currentElement)
			{
			case ElementType::Beam:
			case ElementType::Road:
				rt.draw(gridGizmo, states);
				break;
			}
		}
	}
}
