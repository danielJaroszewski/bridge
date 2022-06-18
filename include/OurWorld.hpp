#pragma once

#include "./OurComponent.hpp"
#include "./OurJoint.hpp"
#include "./StaticComponent.hpp"
#include "box2d/box2d.h"
#include <vector>
#include "../include/Car.hpp"
#include "../include/Ledge.hpp"

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
    vector<OurComponent *> components;
    vector<StaticComponent *> staticComponents;
    vector<OurJoint *> joints;
    Car *car;
    b2Vec2 gravity = b2Vec2(0.0f, gravityFactor);
    unsigned numberOfComponents = 0, numberOfJoints = 0;
    float timeStep;
    int32 velocityIterations, positionIterations;
    int currDynamicCompIndex = 0, currStaticCompIndex = 0;

    /**
     * @brief Initializes components from the components vector.
     *
     */
    void initializeComponents();

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

public:
    /**
     * @brief b2World field - that's what we are wrapping up. Made it public to easily access all
     * properties of it.
     */
    b2World world = b2World(gravity);

    /**
     * @brief Adds dynamic component created earlier. Passing by reference.
     *
     * @param component_ Reference to object OurComponent
     */
    void addComponent(OurComponent &component_);

    /**
     * @brief
     *
     * @param staticComponent_
     */
    void addStaticComponent(StaticComponent &staticComponent_);
    void addJoint(OurJoint &joint_);
    void addCar(Car &car_);

    OurComponent getComponent(int index);
    void setSimParams(float timeStep_ = (1.0f / 60.0f), int32 velocityIterations_ = 8, int32 positionIterations_ = 3);
    void update();

    /**
     * @brief Wrapper function to easily initalize all the components, fixtures and joints. Also defines two edges of the map
     * at xy coordinates of (1,1) and (150,1). Each of them is 20 units wide and 50 units long.
     *
     */
    void initializeWorld();

    /**
     * @brief Clears the world from created joints and bodies.
     *
     */
    void destroyB2Bodies();
};
