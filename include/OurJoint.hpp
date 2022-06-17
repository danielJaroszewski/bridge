#pragma once
#include "box2d/box2d.h"
#include <memory>

/**
 * @brief Wrapper class for box2d's distanceJoint.
 * 
 */
class OurJoint 
{
private:
   b2DistanceJointDef distJointDef; 
   int indexOfBodyA, indexOfBodyB;
   bool isLeftBodyStatic, isRightBodyStatic;


public:
    b2DistanceJoint* distanceJoint;
    const b2DistanceJointDef* getDistJointDef();
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
    void initializeDefinition(b2Body* bodyA_, b2Body* bodyB_ , b2Vec2 aBodyAnchor_, b2Vec2 bBodyAnchor_); //called from world

    /**
     * @brief Sets the stiffnes of a joint.
     * 
     * @param freq_ Oscillation frequency.
     * @param dampingRatio_ Damping ratio. Values starting from 0 can be assigned, with values above 1 being critical damping with no oscillation.
     */
    void setLinearStiffness(float freq_, float dampingRatio_);//must be called after initializeDefinition

    /**
     * @brief Sets the indices of bodies, to which the joint is attached.
     * 
     * @param bodyAIndex 
     * @param bodyBIndex 
     */
    void setIndexOfBodies(int bodyAIndex, int bodyBIndex);


};