#pragma once

#include "box2d/box2d.h"

/**
 * @brief Object moving on the bridge. Two wheels and some simple chassis. 
 * Inspired by the file car.cpp in box2d testbed. 
 * Need to implement some scaling factor.
 */
class Car
{
    private:
    b2PolygonShape chassis;
    b2Vec2 vertices[8];



    public:
    void setVertices();
    
};
