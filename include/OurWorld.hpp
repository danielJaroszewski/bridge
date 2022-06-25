#pragma once

#include "OurComponent.hpp"
#include "OurJoint.hpp"
#include "StaticComponent.hpp"
#include "box2d/box2d.h"
#include <vector>
#include "Car.hpp"
#include "Ledge.hpp"
#include "JoiningPoint.hpp"
#include "Ib2BodyOwner.hpp"

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
    vector<JoiningPoint*> joiningPoints;
    Car *car = nullptr;
    vector<Ib2BodyOwner*> bodyOwners;

    b2Vec2 gravity = b2Vec2(0.0f, gravityFactor);
    unsigned numberOfComponents = 0, numberOfJoints = 0;
    float timeStep;
    int32 velocityIterations, positionIterations;
    int currentCompIndex = 0;

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

    /**
     * @brief Initializes car defnitions, fixtures and parameters.
     * 
     */
    void initializeCar();

public:
    /**
     * @brief b2World field - that's what we are wrapping up. Made it public to easily access all
     * properties of it.
     */
    b2World world = b2World(gravity);

public:
    OurWorld() = default;

    OurWorld(const OurWorld &) = delete;
    OurWorld(OurWorld &&) noexcept = delete;

    OurWorld &operator=(const OurWorld &) = delete;
    OurWorld &operator=(OurWorld &&) noexcept = delete;

    ~OurWorld();
    /**
     * @brief Adds dynamic component created earlier. Passing by reference.
     *
     * @param component_ Reference to object OurComponent
     */
    void addComponent(OurComponent &component_);

    /**
     * @brief Adds static component created earlier. Passing by reference.
     *
     * @param staticComponent_ Reference to object staticComponent
     */
    void addStaticComponent(StaticComponent &staticComponent_);

      /**
     * @brief Adds joint created earlier. Passing by reference.
     *
     * @param staticComponent_ Reference to object OurJoint
     */
    void addJoint(OurJoint &joint_);

      /**
     * @brief Adds car created earlier. Passing by reference.
     *
     * @param staticComponent_ Reference to object Car
     */
    void addCar(Car &car_);
    void addJoiningPoint(JoiningPoint& jPoint_);

    OurComponent &getComponent(int index) const;


    /**
     * @brief Updates world simulation by one step.
     * 
     */
    void update();

    /**
     * @brief Wrapper function to easily initalize all the components, fixtures and joints. 
     *
     */
    void initializeWorld();

    /**
     * @brief Clears the world from created joints and bodies.
     *
     */
    void clearWorld();
};
