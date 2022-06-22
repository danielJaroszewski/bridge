#include "../include/OurComponent.hpp"

OurComponent::OurComponent(float xCoordinate_, float yCoordinate_, float width_, float height_, float density_)
:xCoordinate(xCoordinate_), yCoordinate(yCoordinate_), width(width_), height(height_), density(density_)
{}

void OurComponent::createBodyDefinition()
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = 0.0f;
    bodyDef.angularDamping = 0.1f;
    bodyDef.position.Set(xCoordinate, yCoordinate);
}

void OurComponent::createBodyFixtureDefinition()
{
    dynamicBox.SetAsBox((width) / 2, (height) / 2);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = density;
    fixtureDef.friction =0.9f;
    fixtureDef.filter.categoryBits = DYNAMIC_COMP_CATEGORY;
    fixtureDef.filter.maskBits = DYNAMIC_COMP_MASK;
}

void OurComponent::setUpComponent()
{
    createBodyDefinition();
    createBodyFixtureDefinition();
}

const b2BodyDef* OurComponent::getBodyDef() const
{
    return &bodyDef;
}

const b2FixtureDef* OurComponent::getFixtureDefinition() const
{
    return &fixtureDef;
}

float OurComponent::getXCoordinate() const
{
    return dynBody->GetPosition().x;
}

float OurComponent::getYCoordinate() const
{
    return dynBody->GetPosition().y;
}

float OurComponent::getWidth() const
{
    return width;
}

float OurComponent::getHeight() const
{
    return height;
}

float OurComponent::getAngle() const
{
    return dynBody->GetAngle();
}

b2Vec2 OurComponent::getLeftAnchorPoint() const
{
    const b2Vec2 lAnchor((xCoordinate - (width - 0.5f)), yCoordinate);
    return dynBody->GetWorldPoint(lAnchor);
}

b2Vec2 OurComponent::getRightAnchorPoint() const
{
    const b2Vec2 rAnchor(xCoordinate + (width - 0.5f), yCoordinate);
    return dynBody->GetWorldPoint(rAnchor);
}

void OurComponent::setCompIndex(int ind)
{
    compIndex = ind;
}

int OurComponent::getCompIndex() const
{
    return compIndex;
}