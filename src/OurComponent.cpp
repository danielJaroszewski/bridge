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

b2BodyDef OurComponent::getBodyDef()
{
    return this->bodyDef;
}

float OurComponent::getXCoordinate()
{
    return this->xCoordinate;
}