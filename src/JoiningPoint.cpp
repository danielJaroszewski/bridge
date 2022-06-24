#include "../include/JoiningPoint.hpp"

JoiningPoint::JoiningPoint(float x_, float y_)
:x(x_), y(y_)
{}

void JoiningPoint::createFixtureDefinition()
{
    shape.m_radius = JOINING_POINT_RADIUS;
    fixtureDef.shape = &shape;
    fixtureDef.density = 10.0f;
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