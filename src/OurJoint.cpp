#include "../include/OurJoint.hpp"


void OurJoint::initializeDefinition(b2Body* bodyA_, b2Body* bodyB_ , b2Vec2 aBodyAnchor_, b2Vec2 bBodyAnchor_)
{
    distJointDef.Initialize(bodyA_, bodyB_, aBodyAnchor_, bBodyAnchor_);
    distJointDef.collideConnected = true;
}


void OurJoint::setLinearStiffness(float freq_, float dampingRatio_)
{
    b2LinearStiffness(distJointDef.stiffness, distJointDef.damping, freq_, dampingRatio_, distJointDef.bodyA, distJointDef.bodyB);
}

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

const b2DistanceJointDef* OurJoint::getDistJointDef()
{
    return &distJointDef;
}
