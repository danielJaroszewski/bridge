#include "../include/OurComponent.hpp"

OurComponent::OurComponent(float xCoordinate_, float yCoordinate_, float width_, float height_, float density_)
:xCoordinate(xCoordinate_), yCoordinate(yCoordinate_), width(width_), height(height_), density(density_)
{}

void OurComponent::createBodyDefinition()
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.linearDamping = COMPONENT_LINEAR_DAMPING;
    bodyDef.angularDamping = COMPONENT_ANGULAR_DAMPING;
    bodyDef.position.Set(xCoordinate, yCoordinate);
}

void OurComponent::createBodyFixtureDefinition()
{
    dynamicBox.SetAsBox((width) / 2, (height) / 2);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = density;
    fixtureDef.friction =1.0f;
    fixtureDef.filter.categoryBits = DYNAMIC_COMP_CATEGORY;
    fixtureDef.filter.maskBits = DYNAMIC_COMP_MASK;
}

void OurComponent::setUpComponent()
{
    createBodyFixtureDefinition();
    createBodyDefinition();
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
    const b2Vec2 lAnchor(getXCoordinate() - (width-0.1f), yCoordinate);
    return dynBody->GetWorldPoint(lAnchor);
}

b2Vec2 OurComponent::getRightAnchorPoint() const
{
    const b2Vec2 rAnchor(getXCoordinate() + (width-0.1f), yCoordinate);
    return dynBody->GetWorldPoint(rAnchor);
}

b2Vec2 OurComponent::getCentralAnchorPoint() const
{
    const b2Vec2 cAnchor(xCoordinate + (width/2), yCoordinate + (height/2));
    return dynBody->GetWorldPoint(cAnchor);
}

void OurComponent::setCompIndex(int ind)
{
    compIndex = ind;
}

int OurComponent::getCompIndex() const
{
    return compIndex;
}