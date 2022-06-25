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


    const b2BodyDef* getBodyDef() const;
    const b2FixtureDef* getFixtureDefinition() const;
    float getXCoordinate() const override;
    float getYCoordinate() const override;
    float getWidth() const override;
    float getHeight() const override;
    float getAngle() const override;
    b2Vec2 getAnchorPoint() override;
    b2Vec2 getLeftAnchorPoint(); 
    b2Vec2 getRightAnchorPoint();
    int getCompIndex() const;
    b2Body* getB2Body() override;
    void setReturningLeftAnchor();
    void setReturningRightAnchor();
};