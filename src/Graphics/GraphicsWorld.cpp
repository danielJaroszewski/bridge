#include "../../include/Graphics/GraphicsWorld.hpp"

#include <imgui-SFML.h>
#include <imgui.h>
#include <cmath>

most::GraphicsWorld::GraphicsWorld()
	: view(sf::Vector2f(), sf::Vector2f(800, 600)), viewMoving(false)
{
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
}

most::GraphicsWorld::~GraphicsWorld()
{
	// We need to make sure that owned drawables are destroyed first.
	allDrawables.clear();
	wnd.close();
	ImGui::SFML::Shutdown();
}

void most::GraphicsWorld::processEvents()
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

void most::GraphicsWorld::present()
{
	ImGui::SFML::Update(wnd, deltaClock.restart());
	wnd.clear(sf::Color(66, 135, 245));
	for (const auto& x : allDrawables)
	{
		wnd.draw(*x.first);
	}

	ImGui::SFML::Render(wnd);
	wnd.display();
}

most::GraphicsWorld::EventCallbackHandle most::GraphicsWorld::addEventCallback(EventCallback&& callback)
{
	eventCallbacks.emplace_back(std::move(callback));
	return std::prev(eventCallbacks.end());
}

void most::GraphicsWorld::removeEventCallback(const EventCallbackHandle callback)
{
	eventCallbacks.erase(callback);
}

void most::GraphicsWorld::addDrawable(Drawable* const drawable)
{
	allDrawables.emplace(drawable, nullptr);
}

void most::GraphicsWorld::removeDrawable(Drawable* const drawable)
{
	allDrawables.erase(drawable);
}

sf::Time most::GraphicsWorld::getDeltaTime() const
{
	return deltaClock.getElapsedTime();
}

void most::GraphicsWorld::update()
{
	for (auto& x : allDrawables)
	{
		x.first->update();
	}
}

void most::GraphicsWorld::physicsUpdate()
{
	for (auto& x : allDrawables)
	{
		x.first->physicsUpdate();
	}
}
