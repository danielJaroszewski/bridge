#pragma once

#include "box2d/box2d.h"

/**
 * @brief Class representing object that is supposed not to move under simulation. Two static bodies
 * on the far sides of the world are anchors to which the bridge is connected. Size is constant
 * and the same 
 */
class StaticComponent
{
    private:
    float xCoordinate;  
    float yCoordinate;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape staticBox;


    public:
    b2Body* staticBody;

    StaticComponent(float xCoordinate_, float yCoordninate_);


};