#include "../../include/Graphics/GraphicsWorld.hpp"

#include <imgui-SFML.h>
#include <imgui.h>
#include <cmath>

namespace most
{
	GraphicsWorld* GraphicsWorld::instance = nullptr;

	void GraphicsWorld::loadTextures(const std::string& pathToResources)
	{
#define ASSERT_LOAD(x) if (!((x##Texture).loadFromFile(pathToResources + (#x ".png")))) throw std::runtime_error("Chlopaki nie przeniesliscie " #x ".png do folderu z plikiem wykonywalnym");
		ASSERT_LOAD(wood);
		ASSERT_LOAD(road);
		ASSERT_LOAD(woodLowRes);
		ASSERT_LOAD(roadLowRes);
#undef ASSERT_LOAD
	}

	GraphicsWorld::GraphicsWorld(const std::string& pathToResources)
		: view(sf::Vector2f(), sf::Vector2f(800, 600)), viewMoving(false)
	{
		instance = this;
		wnd.create(sf::VideoMode(800, 600), windowTitle);
		wnd.setVerticalSyncEnabled(true);
		wnd.setView(view);
		ImGui::SFML::Init(wnd);

		addEventCallback([this](const sf::Event& e)
			{
				switch (e.type)
				{
				case sf::Event::MouseWheelScrolled:
					if (e.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
					{
						view.zoom(std::signbit(e.mouseWheelScroll.delta) ? 2.0f : (0.5f));
					}
					break;
				case sf::Event::MouseButtonPressed:
					viewMoving = true;
					lastMousePos = sf::Vector2f(e.mouseButton.x, e.mouseButton.y);
					return;
				case sf::Event::MouseButtonReleased:
					viewMoving = false;
					return;
				case sf::Event::MouseMoved:
					if (viewMoving)
					{
						const auto currentMousePos = sf::Vector2f(e.mouseMove.x, e.mouseMove.y);
						view.setCenter(view.getCenter() + (currentMousePos - lastMousePos));
						lastMousePos = currentMousePos;
					}
					break;
				default:
					return;
				}

				wnd.setView(view);
			});

		loadTextures(pathToResources);
	}

	GraphicsWorld::~GraphicsWorld()
	{
		// We need to make sure that owned drawables are destroyed first.
		allDrawables.clear();
		wnd.close();
		ImGui::SFML::Shutdown();
		if (instance == this)
		{
			instance = nullptr;
		}
	}

	void GraphicsWorld::processEvents()
	{
		sf::Event e;
		while (wnd.pollEvent(e))
		{
			ImGui::SFML::ProcessEvent(e);
			for (const auto& x : eventCallbacks)
			{
				x(e);
			}
		}
	}

	void GraphicsWorld::present()
	{
		wnd.clear(sf::Color(66, 135, 245));
		for (const auto& x : allDrawables)
		{
			wnd.draw(*x.first);
		}

		ImGui::SFML::Render(wnd);
		wnd.display();
	}

	GraphicsWorld::EventCallbackHandle GraphicsWorld::addEventCallback(EventCallback&& callback)
	{
		eventCallbacks.emplace_back(std::move(callback));
		return std::prev(eventCallbacks.end());
	}

	void GraphicsWorld::removeEventCallback(const EventCallbackHandle callback)
	{
		eventCallbacks.erase(callback);
	}

	void GraphicsWorld::addDrawable(Drawable* const drawable)
	{
		allDrawables.emplace(drawable, nullptr);
	}

	void GraphicsWorld::removeDrawable(Drawable* const drawable)
	{
		allDrawables.erase(drawable);
	}

	sf::Time GraphicsWorld::getDeltaTime() const
	{
		return deltaClock.getElapsedTime();
	}

	void GraphicsWorld::update()
	{
		ImGui::SFML::Update(wnd, deltaClock.restart());
		for (auto& x : allDrawables)
		{
			x.first->update();
		}
	}

	void GraphicsWorld::physicsUpdate()
	{
		for (auto& x : allDrawables)
		{
			x.first->physicsUpdate();
		}
	}

	sf::Vector2f most::GraphicsWorld::mousePositionToWorld(const sf::Vector2i& vec) const
	{
		return wnd.mapPixelToCoords(vec);
	}

	const sf::Texture& GraphicsWorld::getWoodTexture() const
	{
		return woodTexture;
	}

	const sf::Texture& GraphicsWorld::getRoadTexture() const
	{
		return roadTexture;
	}

	const sf::Texture& GraphicsWorld::getWoodLowResTexture() const
	{
		return woodLowResTexture;
	}

	const sf::Texture& GraphicsWorld::getRoadLowResTexture() const
	{
		return roadLowResTexture;
	}

	GraphicsWorld* GraphicsWorld::getInstance()
	{
		return instance;
	}
}
