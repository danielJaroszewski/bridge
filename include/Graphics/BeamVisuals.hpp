#pragma once

#include "Drawable.hpp"
#include "../RectPhysicsComponent.hpp"

namespace most
{
	class BeamVisuals
		: public Drawable
	{
	private:
		sf::RectangleShape visuals;
		RectPhysicsComponent& physicalComponent;
	public:
		BeamVisuals(RectPhysicsComponent& comp);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual inline void update() override {};
		virtual void physicsUpdate() override;
	};
}
