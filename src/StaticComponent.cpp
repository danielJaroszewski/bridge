#include "../include/StaticComponent.hpp"

StaticComponent::StaticComponent(float xCoordinate_, float yCoordninate_)
: xCoordinate(xCoordinate_), yCoordinate(yCoordninate_), width(0.5f), height(0.5f)
{
}

void StaticComponent::createBodyDefinition()
{
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(xCoordinate, yCoordinate);
}

void StaticComponent::createBodyFixtureDefinition()
{
    staticBox.SetAsBox(width / 2.0f, height / 2.0f); // constant and the same size
    fixtureDef.shape = &staticBox;
    fixtureDef.filter.categoryBits = STATIC_COMP_CATEGORY;
    fixtureDef.filter.maskBits = STATIC_COMP_MASK;
}

void StaticComponent::setUpStaticComponent()
{
    createBodyDefinition();
    createBodyFixtureDefinition();
}

const b2BodyDef* StaticComponent::getBodyDef()
{
    return &bodyDef;
}

const b2FixtureDef* StaticComponent::getFixtureDefinition()
{
    return &fixtureDef;
}

float StaticComponent::getXCoordinate() const
{
    return staticBody->GetPosition().x;
}

float StaticComponent::getYCoordinate() const
{
    return staticBody->GetPosition().y;
}

float StaticComponent::getWidth() const
{
    return width;
}

float StaticComponent::getHeight() const
{
    return height;
}

float StaticComponent::getAngle() const
{
    return staticBody->GetAngle();
}

b2Vec2 StaticComponent::getAnchorPoint()
{
    return staticBody->GetWorldCenter();
}

bool StaticComponent::isStatic()
{
    return true;
}

void StaticComponent::setIndex(int ind)
{
    compIndex = ind;
}

int StaticComponent::getCompIndex()
{
    return compIndex;
}