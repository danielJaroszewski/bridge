#pragma once

#include "./OurComponent.hpp"
#include "box2d/box2d.h"
#include <vector>

using std::vector;

class OurWorld
{
private:
    float gravityFactor = -10.0f; // to initialize gravity in box2d, default value
    vector<OurComponent> components;
    b2Vec2 gravity = b2Vec2(0.0f, gravityFactor);
    b2World world =b2World(gravity);
    vector<b2Body*> b2Bodies;
public:
    OurWorld(float gravityFactor_);

    // xCoordinate and yCoordinate - coordinates of center of component
    void addComponent(OurComponent& component_);

    void addJoint(OurComponent bodyA, OurComponent bodyB);
    void initialize(); //making box2d world and box2d bodies
    void assignFixtures();
    void destroyB2World();

};
