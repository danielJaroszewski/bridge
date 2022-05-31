#pragma once
#include "box2d/box2d.h"

/**
 * @brief Wrapper class for box2d bodies.
 * 
 */
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
    const b2BodyDef* getBodyDef();
    const b2FixtureDef* getFixtureDefinition();
    float getXCoordinate();
    float getYCoordinate();
    float getLength();
    float getWidth();
    float getAngle();

    /**
    * @brief Creates the body definition to be used by OurWorld.
    * 
    */
    void createBodyDefinition();

    /**
    * @brief Sets body fixture (density, shape, friction).
    * 
    */
    void createBodyFixtureDefinition();
    
};