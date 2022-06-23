#include "../../include/GUI/GUIWorld.hpp"

namespace most
{
	namespace GUI
	{
		World* World::instance = nullptr;

		World::World()
		{
			instance = this;
		}

		World::~World()
		{
			// In case some fucked up.
			if (instance == this)
			{
				instance = nullptr;
			}
		}

		void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
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

		sf::Drawable* World::getScene()
		{
			return currentScene.get();
		}

		const sf::Drawable* World::getScene() const
		{
			return currentScene.get();
		}

		void World::setScene(std::unique_ptr<sf::Drawable>&& scene)
		{
			// I don't swap the scene immediately in case the current scene wants to change the scene.
			if (currentScene)
			{
				newScene = std::move(scene);
			}
			else
			{
				currentScene = std::move(scene);
			}
		}

		World* World::getInstance()
		{
			return instance;
		}
	}
}
