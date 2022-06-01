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
    float width;
    float height;
    float density;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape dynamicBox;

public:
    b2Body* dynBody;

    /**
     * @brief Construct a new Our Component object
     * 
     * @param xCoordinate_ x coordinate of center of component
     * @param yCoordinate_ y coordinate of center of component
     * @param width_ full width of component
     * @param height_ full height of component
     * @param density_ density of component
     */
    OurComponent(float xCoordinate_, float yCoordinate_, float width_, float height_, float density_);

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


    const b2BodyDef* getBodyDef();
    const b2FixtureDef* getFixtureDefinition();
    float getXCoordinate();
    float getYCoordinate();
    float getWidth();
    float getHeight();
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
    
    b2Vec2 getLeftAnchorPoint();
    b2Vec2 getRightAnchorPoint();
};