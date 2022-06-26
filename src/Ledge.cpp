#include "../include/Ledge.hpp"


Ledge::Ledge(float x, float y)
:xCoordinate(x), yCoordinate(y)
{}

void Ledge::createBodyDef()
{
    for(int i=0; i<4; i++)
    {
        ledgeBodyDef[i].type = b2_staticBody;
    }
    ledgeBodyDef[0].position.Set(xCoordinate-1.5*singleBodyWidth, yCoordinate);
    ledgeBodyDef[1].position.Set(xCoordinate-0.5*singleBodyWidth, yCoordinate);
    ledgeBodyDef[2].position.Set(xCoordinate+0.5*singleBodyWidth, yCoordinate);
    ledgeBodyDef[3].position.Set(xCoordinate+1.5*singleBodyWidth, yCoordinate);
}

void Ledge::createFixtureDef()
{
    
    ledgeBox.SetAsBox(singleBodyWidth, LEDGE_FULL_HEIGHT);
    ledgeFixtureDef.shape = &ledgeBox;
    ledgeFixtureDef.filter.categoryBits = LEDGE_CATEGORY;
    ledgeFixtureDef.filter.maskBits = LEDGE_MASK;
}

void Ledge::setUpLedge()
{
    createBodyDef();
    createFixtureDef();
}

const b2BodyDef* Ledge::getBodyDef(int index)
{
   return &ledgeBodyDef[index];
}

const b2FixtureDef* Ledge::getFixtureDef()
{
    return &ledgeFixtureDef;
}

float Ledge::getXCoordinate() const
{
    return xCoordinate;
}

float Ledge::getYCoordinate() const
{
    return yCoordinate;
}

float Ledge::getWidth() const
{
    return LEDGE_FULL_WIDTH;
}

float Ledge::getHeight() const
{
    return LEDGE_FULL_HEIGHT;
}

float Ledge::getAngle() const
{
    return 0.0f; // can be done, because it is static body
}