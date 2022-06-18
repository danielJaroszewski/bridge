#pragma once

#include "Drawable.hpp"
#include "../OurComponent.hpp"

namespace most
{
	class BeamVisuals
		: public Drawable
	{
	private:
		sf::RectangleShape visuals;
		OurComponent& physicalComponent;
	public:
		BeamVisuals(OurComponent& comp);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual inline void update() override {};
		virtual void physicsUpdate() override;
	};
}
