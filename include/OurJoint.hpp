#pragma once
#include "box2d/box2d.h"
#include "Constants.hpp"

/**
 * @brief Wrapper class for box2d's revolute joint
 *
 */
class OurJoint
{
private:
    b2RevoluteJointDef revJointDef;
    int indexOfBodyA, indexOfBodyB;
    bool isBodyAJoiningPoint = false, isBodyBJoiningPoint = false;

    b2RevoluteJoint *revoluteJoint;

    float maxForce;

public:
    friend class OurWorld;
    const b2RevoluteJointDef *getReVJointDef();
    int getBodyAIndex();
    int getBodyBIndex();
    
    /**
     * @brief initializes the definition of joint
     * 
     * @param bodyA_ first body to which joint is attached
     * @param bodyB_ second body to which joint is attached
     * @param anchorPoint anchor point of joint in global coordinates
     */
    void initializeDefinition(b2Body *bodyA_, b2Body *bodyB_, b2Vec2 anchorPoint); 

    /**
     * @brief Sets the indices of bodies to which the joint is attached.
     *
     * @param bodyAIndex index of body A
     * @param bodyBIndex index of body B
     */
    void setIndexOfBodies(int bodyAIndex, int bodyBIndex);

    /**
     * @brief indicates that body A is JoiningPoint object. This method or setBBodyJoiningPoint needs to be called in order to determine the coordinates of anchor point which are got from JoiningPoint
     */
    void setABodyJoiningPoint();

    /**
     * @brief indicates that body B is JoiningPoint object. This method or setABodyJoiningPoint needs to be called in order to determine the coordinates of anchor point which are got from JoiningPoint
     * 
     */
    void setBBodyJoiningPoint();

    /**
     * @brief Absolute force acting on joint
     * 
     * @return float absolute force acting on joint
     */
    float getAbsActingForce();
};