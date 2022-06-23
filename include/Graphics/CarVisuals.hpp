#pragma once

#include "Drawable.hpp"
#include "BeamVisuals.hpp"

#include "../Car.hpp"

namespace most
{
	class CarVisuals
		: public Drawable
	{
	private:
		Car& car;
		sf::RectangleShape rect;
		sf::CircleShape leftWheel, rightWheel;
	public:
		CarVisuals(Car&);

		virtual inline void update() override {};
		virtual void physicsUpdate() override;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
