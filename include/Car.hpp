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
    b2PolygonShape chassisPolygon;
    //b2Vec2 vertices[8];
    b2CircleShape wheel;
    b2BodyDef chassisBodyDef;
    b2BodyDef wheel1BodyDef;
    b2BodyDef wheel2BodyDef;
    b2FixtureDef chassisFixtureDef;
    b2FixtureDef wheelFixtureDef;
    b2WheelJointDef wheel1JointDef;
    b2WheelJointDef wheel2JointDef;

    const float initialHeight = 10.0f;

    void createChassisFixtureDef();
    void setWheelRadius(float radius=0.4f);
    void createChassisBodyDef(); 
    void createWheel1BodyDef();
    void createWheel2BodyDef();
    void createWheelFixtureDef();

    public:
    b2Body* chassisBody;
    b2Body* wheel1Body;
    b2Body* wheel2Body;
    b2WheelJoint* wheel1Joint;
    b2WheelJoint* wheel2Joint;

    void setUpCar(); //to be called
    void createJointDef(); //after creating all bodies

    const b2FixtureDef* getChassisFixtureDef();
    const b2FixtureDef* getWheelFixtureDef();
    const b2BodyDef* getChassisBodyDef();
    const b2BodyDef* getWheel1BodyDef();
    const b2BodyDef* getWheel2BodyDef();
    const b2WheelJointDef* getWheel1JointDef();
    const b2WheelJointDef* getWheel2JointDef();

    float getChassisXCoordinate();
    float getChassisYCoordinate();
    float getLeftWheelXCoordinate();
    float getLeftWheelYCoordinate();
    float getRightWheelXCoordinate();
    float getRightWheelYCoordinate();
    
};
