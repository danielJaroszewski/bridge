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
			if (currentScene)
			{
				target.draw(*currentScene, states);
			}
		}

		void World::update()
		{
			if (newScene)
			{
				currentScene = std::move(newScene);
			}
			if (currentScene)
			{
				currentScene->update();
			}
		}

		void World::physicsUpdate()
		{
			if (newScene)
			{
				currentScene = std::move(newScene);
			}
			if (currentScene)
			{
				currentScene->physicsUpdate();
			}
		}

		Drawable* World::getScene()
		{
			return currentScene.get();
		}

		const Drawable* World::getScene() const
		{
			return currentScene.get();
		}

		void World::setScene(std::unique_ptr<Drawable>&& scene)
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
