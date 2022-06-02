#pragma once

#include "box2d/box2d.h"

/**
 * @brief Class representing object that is supposed not to move under simulation. 
 * Two static bodies on the far sides of the world are anchors to which the bridge is connected. Size is constant and the same .
 * Joints are supposed to be connected to center of the static body. It is not going to be big. 
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

    StaticComponent(float xCoordinate_, float yCoordinate_);
    void createBodyDefinition();
    void createBodyFixtureDefinition();
    const b2BodyDef* getBodyDef();
    const b2FixtureDef* getFixtureDefinition();
    float getXCoordinate();
    float getYCoordinate();

    b2Vec2 getAnchorPoint(); //only one anchor point
};