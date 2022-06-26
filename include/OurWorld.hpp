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
 * @brief Wrapper class for box2d's world. Initializes and places components inside a b2World object, simulating gravity and other forces.
 */

class OurWorld
{
private:
    vector<OurComponent *> components;
    vector<StaticComponent *> staticComponents;
    vector<OurJoint *> joints;
    vector<JoiningPoint*> joiningPoints;
    Car *car = nullptr;
    vector<Ib2BodyOwner*> bodyOwners;
    Ledge* ledge1=nullptr;
    Ledge* ledge2 = nullptr;

    b2Vec2 gravity = b2Vec2(0.0f, GRAVITY);
    unsigned numberOfComponents = 0, numberOfJoints = 0;
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
     * @param component_ object OurComponent
     */
    void addComponent(OurComponent &component_);

    /**
     * @brief Adds static component created earlier. Passing by reference.
     *
     * @param staticComponent_ object staticComponent
     */
    void addStaticComponent(StaticComponent &staticComponent_);

      /**
     * @brief Adds joint created earlier. Passing by reference.
     *
     * @param staticComponent_ object OurJoint
     */
    void addJoint(OurJoint &joint_);

      /**
     * @brief Adds car created earlier. Passing by reference.
     *
     * @param staticComponent_  object Car
     */
    void addCar(Car &car_);

    /**
     * @brief adds joining point
     * 
     * @param jPoint_ joining point object
     */
    void addJoiningPoint(JoiningPoint& jPoint_);

    /**
     * @brief adds ledge object
     * 
     * @param ledge_ ledge object
     */
    void addLedge(Ledge& ledge_);

    /**
     * @brief Get the Component object
     * 
     * @param index index of object
     * @return OurComponent& OurComponent object
     */
    OurComponent &getComponent(int index) const;


    /**
     * @brief Updates world simulation by one step. Step parameters specifed in the constans file
     */
    void update();

    /**
     * @brief Wrapper function to easily initalize all the components, fixtures and joints.
     */
    void initializeWorld();

    /**
     * @brief Clears the world from created joints and bodies.
     */
    void clearWorld();
};
