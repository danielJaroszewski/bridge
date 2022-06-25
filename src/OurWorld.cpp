#include "../include/OurWorld.hpp"

#include <iostream>

OurWorld::~OurWorld()
{
    clearWorld();
}

void OurWorld::addComponent(OurComponent& component_)
{
    component_.setCompIndex(currentCompIndex);
    components.push_back(&component_);
    currentCompIndex++;
    bodyOwners.push_back(&component_);
}
    

void OurWorld::addStaticComponent(StaticComponent &staticComponent_)
{
    staticComponent_.setIndex(currentCompIndex);
    staticComponents.push_back(&staticComponent_);
    currentCompIndex++;
    bodyOwners.push_back(&staticComponent_);
}

void OurWorld::addJoiningPoint(JoiningPoint& jPoint)
{
    jPoint.setIndex(currentCompIndex);
    joiningPoints.push_back(&jPoint);
    bodyOwners.push_back(&jPoint);
    currentCompIndex++;
}

void OurWorld::addJoint(OurJoint &joint_)
{
    joints.push_back(&joint_);
}

void OurWorld::addCar(Car &car_)
{
    car = &car_;
}

void OurWorld::initializeComponents()
{
    for (auto i : components)
    {
        i->dynBody = world.CreateBody(i->getBodyDef());
    }

    for (auto i : staticComponents)
    {
        i->staticBody = world.CreateBody(i->getBodyDef());
    }

    for(auto i : joiningPoints)
    {
        i->body = world.CreateBody(i->getBodyDef());
    }
}

void OurWorld::assignFixtures()
{
    for (auto i : components)
    {
        i->dynBody->CreateFixture(i->getFixtureDefinition());
    }

    for (auto i : staticComponents)
    {
        i->staticBody->CreateFixture(i->getFixtureDefinition());
    }

    for(auto i : joiningPoints)
    {
        i->body->CreateFixture(i->getFixtureDef());
    }

}      

void OurWorld::initializeJoints()
{
    int indexA, indexB;
    for (auto a : joints)
    {
        indexA = a->getBodyAIndex();
        indexB = a->getBodyBIndex();

        if(a->isBodyAJoiningPoint)
        {
            a->initializeDefinition(bodyOwners[indexA]->getB2Body(), 
                                    bodyOwners[indexB]->getB2Body(),
                                    bodyOwners[indexA]->getAnchorPoint());
        }
        else if(a->isBodyBJoiningPoint)
        {
            a->initializeDefinition(bodyOwners[indexA]->getB2Body(), 
                                    bodyOwners[indexB]->getB2Body(),
                                    bodyOwners[indexB]->getAnchorPoint());
        }
        a->revoluteJoint = (b2RevoluteJoint*)world.CreateJoint(a->getReVJointDef());

    } 
}

void OurWorld::initializeCar()
{
    if(car != nullptr)
    {
        car->chassisBody = world.CreateBody(car->getChassisBodyDef());
        car->wheel1Body = world.CreateBody(car->getWheel1BodyDef());
        car->wheel2Body = world.CreateBody(car->getWheel2BodyDef());

        car->chassisBody->CreateFixture(car->getChassisFixtureDef());
        car->wheel1Body->CreateFixture(car->getWheelFixtureDef());
        car->wheel2Body->CreateFixture(car->getWheelFixtureDef()); // fixture is the same

        car->createJointDef();
        car->wheel1Joint = (b2WheelJoint *)world.CreateJoint(car->getWheel1JointDef());
        car->wheel2Joint = (b2WheelJoint *)world.CreateJoint(car->getWheel2JointDef());
    }
}

void OurWorld::initializeWorld()
{
    gravity = b2Vec2(0.0f, gravityFactor);
    world.SetGravity(gravity);
    
    initializeComponents();
    assignFixtures();
    initializeJoints();
    initializeCar();
}

void OurWorld::clearWorld()
{
    for (auto a : components)
    {
        world.DestroyBody(a->dynBody);
    }
    components.clear();
    joints.clear();
    for (auto a : staticComponents)
    {
        world.DestroyBody(a->staticBody);
    }
    staticComponents.clear();
    if(car != nullptr)
    {
        world.DestroyBody(car->chassisBody);
        world.DestroyBody(car->wheel1Body);
        world.DestroyBody(car->wheel2Body);
    }
}
    

OurComponent& OurWorld::getComponent(int index) const
{
    return *components[index];
}

void OurWorld::update()
{
    world.Step(TIME_STEP, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}