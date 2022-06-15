#include "../../include/Graphics/GraphicsWorld.hpp"

#include <imgui-SFML.h>
#include <imgui.h>

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
