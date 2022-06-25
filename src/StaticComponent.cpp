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
    staticBox.SetAsBox(STATIC_COMP_SIZE/2, STATIC_COMP_SIZE/2); // constant and the same size
    fixtureDef.shape = &staticBox;
    fixtureDef.density = STATIC_COMP_DENSITY;
    fixtureDef.filter.categoryBits = STATIC_COMP_CATEGORY;
    fixtureDef.filter.maskBits = STATIC_COMP_MASK;
}

void StaticComponent::setUpStaticComponent()
{  
    createBodyDefinition();
    createBodyFixtureDefinition();
}

const b2BodyDef* StaticComponent::getBodyDef() const
{
    return &bodyDef;
}

const b2FixtureDef* StaticComponent::getFixtureDefinition() const
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
    return STATIC_COMP_SIZE;
}

float StaticComponent::getHeight() const
{
    return STATIC_COMP_SIZE;
}

float StaticComponent::getAngle() const
{
    return staticBody->GetAngle();
}

bool StaticComponent::isStatic() const
{
    return true;
}

void StaticComponent::setIndex(int ind)
{
    compIndex = ind;
}

int StaticComponent::getCompIndex() const
{
    return compIndex;
}

b2Body* StaticComponent::getB2Body()
{
    return staticBody;
}

b2Vec2 StaticComponent::getAnchorPoint()
{
    return staticBody->GetWorldCenter();
}