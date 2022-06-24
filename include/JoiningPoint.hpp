#pragma once
#include "box2d/box2d.h"
#include "Constants.hpp"

class JoiningPoint
{
private:
    b2CircleShape shape;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2Body* body;
    float x, y;
    
    void createFixtureDefinition();
    void createBodyDefinition();

public:
    JoiningPoint(float x_, float y_);

    void setUpJoiningPoint();
    float getXCoordinate();
    float getYCoordinate();
    float getRadius();


};
