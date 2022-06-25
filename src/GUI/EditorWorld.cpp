#include "../../include/GUI/GameWorld.hpp"
#include "../../include/GUI/GUIWorld.hpp"
#include "../../include/GUI/EditorWorld.hpp"

#include "../../include/Graphics/GraphicsWorld.hpp"

#include <imgui.h>
#include <imgui-SFML.h>

namespace most
{
	namespace GUI
	{
		decltype(EditorWorld::maxDistances) EditorWorld::maxDistances = {10.0f, 10.0f};

		EditorWorld::EditorWorld()
			: woodSprite(GraphicsWorld::getInstance()->getWoodLowResTexture()), roadSprite(GraphicsWorld::getInstance()->getRoadLowResTexture())
		{
		}

		void EditorWorld::draw(sf::RenderTarget& rt, sf::RenderStates states) const
		{
			if (ImGui::Begin("Toolbox"))
			{
				if (ImGui::ImageButton(woodSprite))
				{
					currentElement = CurrentElement::Beam;
				}
				if (ImGui::ImageButton(roadSprite))
				{
					currentElement = CurrentElement::Road;
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
}
