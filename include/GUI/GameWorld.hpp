#pragma once

#include "../Graphics/Drawable.hpp"

namespace most
{
	namespace GUI
	{
		class GameWorld
			: public Drawable
		{
		public:
			virtual inline void physicsUpdate() override {};
			virtual inline void update() override {};
			virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
		};
	}
}
