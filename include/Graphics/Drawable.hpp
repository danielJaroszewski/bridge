#pragma once

#include "SFML/Graphics.hpp"

namespace most
{
	class Drawable
		: public sf::Drawable
	{
	public:
		virtual void update() = 0;
		virtual void physicsUpdate() = 0;
	};
}
