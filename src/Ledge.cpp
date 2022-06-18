#include "../include/Ledge.hpp"


Ledge::Ledge(float x, float y)
:xCoordinate(x), yCoordinate(y)
{}

void Ledge::createBodyDef()
{
    ledgeBodyDef.type = b2_staticBody;
    ledgeBodyDef.position.Set(xCoordinate, yCoordinate);
}

void Ledge::createFixtureDef()
{
    ledgeBox.SetAsBox(20.0f, 10.0f);
    ledgeFixtureDef.shape = &ledgeBox;
}

void Ledge::setUpLedge()
{
    createBodyDef();
    createFixtureDef();
}

const b2BodyDef* Ledge::getBodyDef()
{
    return &ledgeBodyDef;
}

const b2FixtureDef* Ledge::getFixtureDef()
{
    return &ledgeFixtureDef;
}


float Ledge::getCenterX()
{
    return xCoordinate;
}

float Ledge::getCenterY()
{
    return yCoordinate;
}

float Ledge::getLeftEdgeXCoordinate()
{
    return xCoordinate - 10.0f;
}

float Ledge::getLeftEdgeYCoordinate()
{
    return yCoordinate + 5.0f;
}

float Ledge::getRightEdgeXCoordinate()
{
     return xCoordinate + 10.0f;
}


float Ledge::getRightEdgeYCoordinate()
{
    return yCoordinate + 5.0f;
}