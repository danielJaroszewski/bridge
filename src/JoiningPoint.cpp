#include "../include/JoiningPoint.hpp"

JoiningPoint::JoiningPoint(float x_, float y_)
:x(x_), y(y_)
{}

void JoiningPoint::createFixtureDefinition()
{
    shape.m_radius = JOINING_POINT_RADIUS;
    fixtureDef.shape = &shape;
    fixtureDef.density = 10.0f;
    fixtureDef.filter.categoryBits = JOINING_POINT_CATEGORY;
    fixtureDef.filter.maskBits = JOINING_POINT_MASK;
}

void JoiningPoint::createBodyDefinition()
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
}

void JoiningPoint::setUpJoiningPoint()
{
    createFixtureDefinition();
    createBodyDefinition();
}

float JoiningPoint::getXCoordinate()
{
    return body->GetPosition().x;
}

float JoiningPoint::getYCoordinate()
{
    return body->GetPosition().y;
}

float JoiningPoint::getRadius()
{
    return JOINING_POINT_RADIUS;
}

b2Body* JoiningPoint::getB2Body()
{
    return body;
}

void JoiningPoint::setIndex(int index_)
{
    index = index_;
}

const b2BodyDef* JoiningPoint::getBodyDef()
{
    return &bodyDef;
}

const b2FixtureDef* JoiningPoint::getFixtureDef()
{
    return &fixtureDef;
}

int JoiningPoint::getIndex()
{
    return index;
}