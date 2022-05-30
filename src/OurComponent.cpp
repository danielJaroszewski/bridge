#include "../include/OurComponent.hpp"

OurComponent::OurComponent(float xCoordinate_, float yCoordinate_, float length_, float width_, float density_)
:xCoordinate(xCoordinate_), yCoordinate(yCoordinate_), length(length_), width(width_), density(density_)
{}

/**
 * @brief Creates the body definition to be used by OurWorld.
 * 
 */
void OurComponent::createBodyDefinition()
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(this->xCoordinate, this->yCoordinate);
    // ...
}

/**
 * @brief Sets body fixture (density, shape, friction).
 * 
 */
void OurComponent::createBodyFixtureDefinition()
{
    dynamicBox.SetAsBox(1.0f, 1.0f);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = this->density;
    fixtureDef.friction =0.3f;
}


const b2BodyDef* OurComponent::getBodyDef()
{
    return &bodyDef;
}

const b2FixtureDef* OurComponent::getFixtureDefinition()
{
    return &fixtureDef;
}

float OurComponent::getXCoordinate()
{
    return this->dynBody->GetPosition().x;
}

float OurComponent::getYCoordinate()
{
    return this->dynBody->GetPosition().y;
}

float OurComponent::getLength()
{
    return this->length;
}

float OurComponent::getWidth()
{
    return this->width;
}