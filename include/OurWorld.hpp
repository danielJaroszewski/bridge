#pragma once

#include "./OurComponent.hpp"
#include "./OurJoint.hpp"
#include "box2d/box2d.h"
#include <vector>

using std::vector;

/**
 * @brief Wrapper class for box2d's world. Initializes and places components inside a b2World object, simulating
 * gravity and other forces.
 * 
 */

class OurWorld
{
private:
    float gravityFactor = -10.0f; // to initialize gravity in box2d, default value
    vector<OurComponent*> components;
    vector<OurJoint*> joints;
    b2Vec2 gravity = b2Vec2(0.0f, gravityFactor);
    unsigned numberOfComponents = 0, numberOfJoints = 0;
    float timeStep;
    int32 velocityIterations, positionIterations;

    

public:
    b2World world =b2World(gravity);
    OurComponent getComponent(int index);
    void addComponent(OurComponent& component_);
    void addJoint(OurJoint& joint_);
    void setSimParams(float timeStep_=(1.0f/60.0f),int32 velocityIterations_=8, int32 positionIterations_ =3);
    void update();
    
    /**
    * @brief Wrapper function to easily initalize all the components, fixtures and joints.
    * 
    */
    void initializeWorld();

    /**
    * @brief Initializes components from the components vector.
    * 
    */
    void initializeComponents(); //making box2d world and box2d bodies

    /**
    * @brief Initializes joints from the joint vector.
    * 
    */
    void initializeJoints();
    /**
    * @brief Initializes fixtures for the created components.
    * 
    */
    void assignFixtures();

    /**
    * @brief Clears the world from created joints and bodies.
    * 
    */
    void destroyB2Bodies();
    
};
