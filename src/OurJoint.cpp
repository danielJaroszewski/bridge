#include "../include/OurJoint.hpp"

/**
 * @brief Initializes the joint definition.
 * 
 * @param bodyA_ First body the joint is attached to.
 * @param bodyB_ Second body the joint is attached to.
 * @param aBodyAnchor_ Coordinates within the first body to which the joint is attached to.
 * @param bBodyAnchor_ Coordinates within the second body to which the joint is attached to.
 */
void OurJoint::initializeDefinition(b2Body* bodyA_, b2Body* bodyB_ , b2Vec2 aBodyAnchor_, b2Vec2 bBodyAnchor_)
{
    distJointDef.Initialize(bodyA_, bodyB_, aBodyAnchor_, bBodyAnchor_);
    distJointDef.collideConnected = true;
}

/**
 * @brief Sets the stiffnes of a joint.
 * 
 * @param freq_ Oscillation frequency.
 * @param dampingRatio_ Damping ratio. Values starting from 0 can be assigned, with values above 1 being critical damping with no oscillation.
 */
void OurJoint::setLinearStiffness(float freq_, float dampingRatio_)
{
    b2LinearStiffness(distJointDef.stiffness, distJointDef.damping, freq_, dampingRatio_, distJointDef.bodyA, distJointDef.bodyB);
}
/**
 * @brief Sets the indices of bodies, to which the joint is attached.
 * 
 * @param bodyAIndex 
 * @param bodyBIndex 
 */
void OurJoint::setIndexOfBodies(int bodyAIndex, int bodyBIndex)
{
    indexOfBodyA = bodyAIndex;
    indexOfBodyB = bodyBIndex;
}

int OurJoint::getBodyAIndex()
{
    return indexOfBodyA;
}


int OurJoint::getBodyBIndex()
{
    return indexOfBodyB;
}

