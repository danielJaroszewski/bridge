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
<<<<<<< HEAD
		//throw std::exception("Not implemented");
=======
		throw std::runtime_error("Not implemented");
>>>>>>> 899480900e7f6d72b9d5a9cf1ab6fc2f2e5b0878
	}

	void GameScene::draw(sf::RenderTarget& rt, sf::RenderStates states) const
	{
		if (currentLevel)
		{
			rt.draw(*currentLevel, states);
		}
	}
}
