#pragma once

#include "./OurComponent.hpp"
#include "./OurJoint.hpp"
#include "box2d/box2d.h"
#include <vector>

using std::vector;

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
    void initializeComponents(); //making box2d world and box2d bodies
    void initializeJoints();
    void assignFixtures();
    void destroyB2BodiesAndJoints();

    OurComponent getComponent(int index);

};
