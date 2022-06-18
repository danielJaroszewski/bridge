#include "../include/GameScene.hpp"

namespace most
{
	void GameScene::setLevel(std::unique_ptr<Level>&& level)
	{
		currentLevel = std::move(level);
	}

	void GameScene::loadLevel(const std::string& filename)
	{
		throw std::exception("Not implemented");
	}

	void GameScene::draw(sf::RenderTarget& rt, sf::RenderStates states) const
	{
		if (currentLevel)
		{
			rt.draw(*currentLevel, states);
		}
	}
}
