#pragma once
#include "box2d/box2d.h"
#include "Constants.hpp"
#include "RectPhysicsComponent.hpp"
#include "Ib2BodyOwner.hpp"

/**
 * @brief Wrapper class for box2d bodies.
 * 
 */
class OurComponent
    : public most::RectPhysicsComponent,
      public Ib2BodyOwner
{
private:
    float xCoordinate;  
    float yCoordinate;
    float width;
    float height;
    float angle;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape dynamicBox;
    void createBodyDefinition();
    void createBodyFixtureDefinition();
    int compIndex;
    b2Body* dynBody;
    void setCompIndex(int ind);
    bool returnLeftAnchor = false, returnRightAnchor = false;
    const b2BodyDef* getBodyDef() const;
    const b2FixtureDef* getFixtureDefinition() const;
    b2Body* getB2Body() override;
    b2Vec2 getLeftAnchorPoint(); 
    b2Vec2 getRightAnchorPoint();


public:
   
    friend class OurWorld;
    /**
     * @brief Construct a new Our Component object
     * 
     * @param xCoordinate_ x corrdinate of center of component
     * @param yCoordinate_ y corrdinate of center of component
     * @param width_ full width of component
     * @param height_ full height of component
     * @param angle angle in degrees rotating clock-wise
     */
    OurComponent(float xCoordinate_, float yCoordinate_, float width_, float height_, float angle);

    

    /**
     * @brief Setting up dynamic component. Only method to be called after creating
     */
    void setUpComponent();


    /**
     * @brief get x coordinate of center
     * 
     * @return float x of center
     */
    float getXCoordinate() const override;

    /**
     * @brief get y coordinate of center
     * 
     * @return float y of center
     */
    float getYCoordinate() const override;

    /**
     * @brief Get the full width
     * 
     * @return float full width
     */
    float getWidth() const override;

    /**
     * @brief Get the full height
     * 
     * @return float full height
     */
    float getHeight() const override;

    /**
     * @brief Get the angle in degreed
     * 
     * @return float angle in degrees
     */
    float getAngle() const override;

    /**
     * @brief Get the vector(x,y) of anchoring point - left or right side
     * 
     * @return b2Vec2 global vector(x,y) of where is anchoring point
     */
    b2Vec2 getAnchorPoint() override;
    
    /**
     * @brief get index of component in world class
     * 
     * @return int index of component stored in world class
     */
    int getCompIndex() const;

    /**
     * @brief call to set the returning anchor point to be the one one the left side of component(in local coordinates system)
     */
    void setReturningLeftAnchor();

    /**
     * @brief call to set the returning anchor point to be the one one the right side of component(in local coordinates system_
     */
    void setReturningRightAnchor();
};