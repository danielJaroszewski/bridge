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
    ledgeBox.SetAsBox(LEDGE_HALF_WIDTH, LEDGE_HALF_HEIGHT);
    ledgeFixtureDef.shape = &ledgeBox;
    ledgeFixtureDef.filter.categoryBits = LEDGE_CATEGORY;
    ledgeFixtureDef.filter.maskBits = LEDGE_MASK;
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
    return b2Ledge->GetPosition().x;
}

float Ledge::getCenterY()
{
    return b2Ledge->GetPosition().y;
}

float Ledge::getLeftEdgeXCoordinate()
{
    return xCoordinate - LEDGE_HALF_WIDTH;
}

float Ledge::getLeftEdgeYCoordinate()
{
    return yCoordinate + LEDGE_HALF_HEIGHT;
}

float Ledge::getRightEdgeXCoordinate()
{
     return xCoordinate + LEDGE_HALF_WIDTH;
}


float Ledge::getRightEdgeYCoordinate()
{
    return yCoordinate + LEDGE_HALF_HEIGHT;
}