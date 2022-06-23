#pragma once

#include "box2d/box2d.h"
#include "Constants.hpp"
#include "RectPhysicsComponent.hpp"

/**
 * @brief Class representing object that is supposed not to move under simulation.
 * Two static bodies on the far sides of the world are anchors to which the bridge is connected. Size is constant and the same .
 * Joints are supposed to be connected to center of the static body. It is not going to be big.
 * Size is constant - 0.25 x 0.25x
 */
class StaticComponent
    : public most::RectPhysicsComponent
{
private:
    float xCoordinate;
    float yCoordinate;
    float width;
    float height;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2PolygonShape staticBox;
    void createBodyDefinition();
    void createBodyFixtureDefinition();
    int compIndex;
    b2Body *staticBody;
    void setIndex(int ind);

public:
    friend class OurWorld;

    StaticComponent(float xCoordinate_, float yCoordinate_);

    const b2BodyDef *getBodyDef();
    const b2FixtureDef *getFixtureDefinition();
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

    b2Vec2 getAnchorPoint(); // only one anchor point
    bool isStatic();
    int getCompIndex();
};