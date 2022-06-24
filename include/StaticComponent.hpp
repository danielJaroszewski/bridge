#pragma once

#include "box2d/box2d.h"
#include "Constants.hpp"
#include "RectPhysicsComponent.hpp"
#include "Ib2BodyOwner.hpp"

/**
 * @brief Class representing object that is supposed not to move under simulation.
 * Two static bodies on the far sides of the world are anchors to which the bridge is connected. Size is constant and the same .
 * Joints are supposed to be connected to center of the static body. It is not going to be big.
 * Size is constant
 */
class StaticComponent
    : public most::RectPhysicsComponent,
      public Ib2BodyOwner
{
private:
    float xCoordinate;
    float yCoordinate;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape staticBox;
    
    int compIndex;
    b2Body *staticBody;

    void setIndex(int ind);
    void createBodyDefinition();
    void createBodyFixtureDefinition();
public:
    StaticComponent(float xCoordinate_, float yCoordinate_);

    const b2BodyDef *getBodyDef() const;
    const b2FixtureDef *getFixtureDefinition() const;
    float getXCoordinate() const override;
    float getYCoordinate() const override;
    float getWidth() const override;
    float getHeight() const override;
    float getAngle() const override;

    /**
     * @brief Setting up static component. Only method to be called after creating
     *
     */
    void setUpStaticComponent();

    bool isStatic() const;
    int getCompIndex() const;

    b2Body* getB2Body() override;
    b2Vec2 getAnchorPoint() override;

    friend class OurWorld;
};