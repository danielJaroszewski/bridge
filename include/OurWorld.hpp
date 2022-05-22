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
    b2World world =b2World(gravity);

public:
    OurWorld(float gravityFactor_);
    void addComponent(OurComponent& component_);
    void addJoint(OurJoint& joint_);
    void initializeWorld();
    void initializeComponents(); //making box2d world and box2d bodies
    void initializeJoints();
    void assignFixtures();
    void destroyB2BodiesAndJoints();

    OurComponent getComponent(int index);

};
