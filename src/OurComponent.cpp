#include "../include/OurComponent.hpp"

OurComponent::OurComponent(float xCoordinate_, float yCoordinate_, float width_, float height_, float density_)
:xCoordinate(xCoordinate_), yCoordinate(yCoordinate_), width(width_), height(height_), density(density_)
{}

void OurComponent::createBodyDefinition()
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(this->xCoordinate, this->yCoordinate);
    // ...
}

void OurComponent::createBodyFixtureDefinition()
{
    dynamicBox.SetAsBox((this->width)/2,(this->height)/2);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = this->density;
    fixtureDef.friction =0.3f;
}

void OurComponent::setUpComponent()
{
    createBodyDefinition();
    createBodyFixtureDefinition();
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

float OurComponent::getWidth()
{
    return this->width;
}

float OurComponent::getHeight()
{
    return this->height;
}

float OurComponent::getAngle()
{
    return this->dynBody->GetAngle();
}

b2Vec2 OurComponent::getLeftAnchorPoint()
{
    b2Vec2 lAnchor = b2Vec2((this->xCoordinate-(this->width-0.5f)), this->yCoordinate);
    b2Vec2 globalLeftAnchor = this->dynBody->GetWorldPoint(lAnchor);
    return globalLeftAnchor;
}

b2Vec2 OurComponent::getRightAnchorPoint()
{
    b2Vec2 rAnchor = b2Vec2(this->xCoordinate+(this->width-0.5f), this->yCoordinate);
    b2Vec2 gloabalRightAnchor = this->dynBody->GetWorldPoint(rAnchor);
    return gloabalRightAnchor;
}