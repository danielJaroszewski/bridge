#include "../../include/GUI/GUIWorld.hpp"

#include <imgui-SFML.h>

void most::GUI::World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (newScene)
	{
		currentScene = std::move(newScene);
	}
	if (currentScene)
	{
		target.draw(*currentScene, states);
	}
}

sf::Drawable* most::GUI::World::getScene()
{
	return currentScene.get();
}

const sf::Drawable* most::GUI::World::getScene() const
{
	return currentScene.get();
}

void most::GUI::World::setScene(std::unique_ptr<sf::Drawable>&& scene)
{
	// I don't swap the scene immediiately in case the current scene wants to change the scene.
	if (currentScene)
	{
		newScene = std::move(scene);
	}
	else
	{
		currentScene = std::move(scene);
	}
}
