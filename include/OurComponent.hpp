#pragma once
#include "box2d/box2d.h"


class OurComponent 
{
private:
    float xCoordinate;
    float yCoordinate;
    float length;
    float width;
    float density;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape dynamicBox;

public:
    b2Body* dynBody;
    OurComponent(float xCoordinate_, float yCoordinate_, float length_, float width_, float density_);
    void createBodyDefinition();
    void createBodyFixtureDefinition();
    const b2BodyDef* getBodyDef();
    const  b2FixtureDef* getFixtureDefinition();
    float getXCoordinate();
};