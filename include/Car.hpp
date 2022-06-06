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
    b2CircleShape wheel;
    b2BodyDef bodyDef;
    b2FixtureDef chassisFixtureDef;
    b2FixtureDef wheelFixtureDef;


    public:
    void createChassisFixtureDef(); //0
    void setWheelRadius(float radius=0.4f); //1
    void createBodyDef(); //2
    void createWheelFixtureDef(); //3

    const b2FixtureDef* getChassisFixtureDef();
    const b2FixtureDef* getWheelFixtureDef();
    
    
    
};
