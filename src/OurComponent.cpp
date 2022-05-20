#include "../include/OurComponent.hpp"

OurComponent::OurComponent(float xCoordinate_, float yCoordinate_, float length_, float width_, float density_)
:xCoordinate(xCoordinate_), yCoordinate(yCoordinate_), length(length_), width(width_), density(density_)
{}


void OurComponent::createBodyDefinition()
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(this->xCoordinate, this->yCoordinate);
    // ...
}

void OurComponent::createBodyFixtureDefinition()
{
    dynamicBox.SetAsBox(1.0f, 1.0f);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = this->density;
    fixtureDef.friction =0.3f;
}

b2BodyDef OurComponent::getBodyDef()
{
    return bodyDef;
}

b2FixtureDef OurComponent::getFixtureDefinition()
{
    return fixtureDef;
}

float OurComponent::getXCoordinate()
{
    return this->xCoordinate;
}

