#include "../../include/Graphics/GraphicsWorld.hpp"

#include <imgui-SFML.h>

most::GraphicsWorld::GraphicsWorld()
{
	wnd.create(sf::VideoMode(800, 600), windowTitle);
	wnd.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(wnd);
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
	wnd.clear();
	for (const auto& x : allDrawables)
	{
		wnd.draw(*x.first);
	}

	ImGui::SFML::Render();
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

void most::GraphicsWorld::addDrawable(sf::Drawable* const drawable)
{
	allDrawables.emplace(drawable, nullptr);
}

void most::GraphicsWorld::addDrawable(std::unique_ptr<sf::Drawable>&& drawable)
{
	const auto ptr = drawable.get(); // Explicit sequencing point.
	allDrawables.emplace(ptr, std::move(drawable));
}

void most::GraphicsWorld::removeDrawable(sf::Drawable* const drawable)
{
	allDrawables.erase(drawable);
}
