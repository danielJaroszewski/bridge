#include "../include/GameScene.hpp"

#include <stdexcept>

namespace most
{
	void GameScene::setLevel(std::unique_ptr<Level>&& level)
	{
		currentLevel = std::move(level);
	}

	void GameScene::loadLevel(const std::string& filename)
	{
		throw std::runtime_error("Not implemented");
	}

	void GameScene::draw(sf::RenderTarget& rt, sf::RenderStates states) const
	{
		if (currentLevel)
		{
			rt.draw(*currentLevel, states);
		}
	}
}
