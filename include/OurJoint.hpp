#pragma once
#include "box2d/box2d.h"

/**
 * @brief Wrapper class for box2d's distanceJoint.
 * 
 */
class OurJoint 
{
private:
   b2DistanceJointDef distJointDef; 
   int indexOfBodyA, indexOfBodyB;
  
public:
    b2DistanceJoint* distanceJoint;
    const b2DistanceJointDef* getDistJointDef();
    void initializeDefinition(b2Body* bodyA_, b2Body* bodyB_ , b2Vec2 aBodyAnchor_, b2Vec2 bBodyAnchor_); //called from world
    void setLinearStiffness(float freq_, float dampingRatio_);//must be called after initializeDefinition
    void setIndexOfBodies(int bodyAIndex, int bodyBIndex);
    int getBodyAIndex();
    int getBodyBIndex();
    
    
};