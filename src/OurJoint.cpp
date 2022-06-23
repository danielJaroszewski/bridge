#include "../include/OurJoint.hpp"


void OurJoint::initializeDefinition(b2Body* bodyA_, b2Body* bodyB_ , b2Vec2 aBodyAnchor_, b2Vec2 bBodyAnchor_)
{
    distJointDef.Initialize(bodyA_, bodyB_, aBodyAnchor_, bBodyAnchor_);
    distJointDef.collideConnected = false;
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

void OurJoint::setLeftBodyStatic()
{
    isLeftBStatic = true;
}

void OurJoint::setRightBodyStatic()
{
    isRightBStatic = true;
}

bool OurJoint::isLeftBodyStatic()
{
    return isLeftBStatic;
}

bool OurJoint::isRightBodyStatic()
{
    return isRightBStatic;
}

float OurJoint::getAbsActingForce()
{
    b2Vec2 force = distanceJoint->GetReactionForce(1/TIME_STEP);
    float modulus = sqrt(pow(force.x, 2) + pow(force.y, 2));
    return modulus;
}