#pragma once

#include <SFML/Graphics.hpp>

namespace most
{
	namespace GUI
	{
		class GameWorld
			: public sf::Drawable
		{
		public:
			virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
		};
	}
}
