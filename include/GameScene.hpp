#pragma once

#include "Level.hpp"

namespace most
{
	class GameScene
		: public sf::Drawable
	{
	private:
		std::unique_ptr<Level> currentLevel;
	public:
		void setLevel(std::unique_ptr<Level>&& level);
		void loadLevel(const std::string& filename);

		virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
	};
}
