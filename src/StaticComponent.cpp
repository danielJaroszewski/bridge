#include "../include/StaticComponent.hpp"

StaticComponent::StaticComponent(float xCoordinate_, float yCoordninate_)
: xCoordinate(xCoordinate_), yCoordinate(yCoordninate_)
{
}

void StaticComponent::createBodyDefinition()
{
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(xCoordinate, yCoordinate);
}

void StaticComponent::createBodyFixtureDefinition()
{
    staticBox.SetAsBox(0.25f, 0.25f); // constant and the same size
    fixtureDef.shape = &staticBox;
}

const b2BodyDef* StaticComponent::getBodyDef()
{
    return &bodyDef;
}

const b2FixtureDef* StaticComponent::getFixtureDefinition()
{
    return &fixtureDef;
}