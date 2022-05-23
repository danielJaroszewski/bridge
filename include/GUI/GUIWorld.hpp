#pragma once

#include <SFML/Graphics.hpp>

namespace most
{
	namespace GUI
	{
		class World
			: public sf::Drawable
		{
		protected:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		};
	}
}
