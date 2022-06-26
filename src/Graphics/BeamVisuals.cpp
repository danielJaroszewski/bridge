#include "../../include/Graphics/BeamVisuals.hpp"

most::BeamVisuals::BeamVisuals(RectPhysicsComponent& comp)
	: visuals(), physicalComponent(comp)
{
	visuals.setFillColor(sf::Color::White);
	visuals.setSize(sf::Vector2f(comp.getWidth(), comp.getHeight()));
	visuals.setOrigin(sf::Vector2f(comp.getWidth() / 2.0f, comp.getHeight() / 2.0f));;
}

void most::BeamVisuals::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(visuals, states);
}

void most::BeamVisuals::physicsUpdate()
{
	visuals.setPosition(sf::Vector2f(physicalComponent.getXCoordinate(), -physicalComponent.getYCoordinate()));
	visuals.setRotation(physicalComponent.getAngle());
}
