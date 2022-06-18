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

float StaticComponent::getXCoordinate()
{
    return staticBody->GetPosition().x;
}

float StaticComponent::getYCoordinate()
{
    return staticBody->GetPosition().y;
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