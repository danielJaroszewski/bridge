#pragma once
#include "box2d/box2d.h"
#include "Constants.hpp"
#include "Ib2BodyOwner.hpp"

/**
 * @brief Small round dynamic body to which joint should be connected
 * 
 */
class JoiningPoint : public Ib2BodyOwner
{
private:
    b2CircleShape shape;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2Body* body;
    float x, y;
    int index;
    
    void createFixtureDefinition();
    void createBodyDefinition();
    const b2BodyDef* getBodyDef();
    const b2FixtureDef* getFixtureDef();
    b2Body* getB2Body() override;
    void setIndex(int index_);

public:
    /**
     * @brief Construct a new Joining Point object
     * 
     * @param x_ x coordinate
     * @param y_ y coordinate
     */
    JoiningPoint(float x_, float y_);
    /**
     * @brief Set the Up Joining Point object. Call after creating.
     * 
     */
    void setUpJoiningPoint();

    float getXCoordinate() const;
    float getYCoordinate() const;
    float getRadius() const;
    float getAngle() const;
    
    int getIndex();
    b2Vec2 getAnchorPoint() override;

    friend class OurWorld;

};
