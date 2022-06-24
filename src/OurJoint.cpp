#include "../include/OurJoint.hpp"


void OurJoint::initializeDefinition(b2Body* bodyA_, b2Body* bodyB_ , b2Vec2 anchorPoint)
{
    revJointDef.bodyA = bodyA_;
    revJointDef.bodyB  = bodyB_;
    revJointDef.Initialize(bodyA_, bodyB_, anchorPoint);
    revJointDef.collideConnected = true;

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

const b2RevoluteJointDef* OurJoint::getReVJointDef()
{
    return &revJointDef;
}


float OurJoint::getAbsActingForce()
{
    b2Vec2 force = revoluteJoint->GetReactionForce(1/TIME_STEP);
    float modulus = sqrt(pow(force.x, 2) + pow(force.y, 2));
    return modulus;
}

void OurJoint::setABodyJoiningPoint()
{
    isBodyAJoiningPoint = true;
}

void OurJoint::setBBodyJoiningPoint()
{
    isBodyBJoiningPoint = true;
}