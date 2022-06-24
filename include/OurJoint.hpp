#pragma once
#include "box2d/box2d.h"
#include "Constants.hpp"

/**
 * @brief Wrapper class for box2d's distanceJoint.
 *
 */
class OurJoint
{
private:
    b2RevoluteJointDef revJointDef;
    int indexOfBodyA, indexOfBodyB;
    bool isMarginalLeft = false, isMarginalRight = false;
    bool isBeamOnTheRight, isBeamOnTheLeft;

    b2RevoluteJoint *revoluteJoint;

    float maxForce; //=??? to be found out

public:
    friend class OurWorld;
    const b2RevoluteJointDef *getReVJointDef();
    int getBodyAIndex();
    int getBodyBIndex();

    /**
     * @brief Initializes the joint definition.
     *
     * @param bodyA_ First body the joint is attached to.
     * @param bodyB_ Second body the joint is attached to.
     * @param aBodyAnchor_ Coordinates within the first body to which the joint is attached to.
     * @param bBodyAnchor_ Coordinates within the second body to which the joint is attached to.
     */
    void initializeDefinition(b2Body *bodyA_, b2Body *bodyB_, b2Vec2 anchorPoint); // called from world

    /**
     * @brief Sets the indices of bodies to which the joint is attached.
     *
     * @param bodyAIndex
     * @param bodyBIndex
     */
    void setIndexOfBodies(int bodyAIndex, int bodyBIndex);

    float getAbsActingForce();
};