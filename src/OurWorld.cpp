#include "../include/OurWorld.hpp"

#include <iostream>

OurWorld::~OurWorld()
{
    destroyB2Bodies();
}

void OurWorld::addComponent(OurComponent& component_)
{
    components.push_back(&component_);
}

void OurWorld::addStaticComponent(StaticComponent& staticComponent_)
{
    staticComponents.push_back(&staticComponent_);
}

void OurWorld::addJoint(OurJoint& joint_)
{
    joints.push_back(&joint_);
}

void OurWorld::initializeComponents()
{
    for(auto i:components)
    {
        i->dynBody = world.CreateBody(i->getBodyDef());
    }

    for(auto i:staticComponents)
    { 
        i->staticBody = world.CreateBody(i->getBodyDef()); 
    }

    car.carBody = world.CreateBody(car.getBodyDef());
}


void OurWorld::assignFixtures()
{
    for(auto i :components)
    {
        i->dynBody->CreateFixture(i->getFixtureDefinition());
    }

    for(auto i:staticComponents)
    {
        i->staticBody->CreateFixture(i->getFixtureDefinition());
    }

    car.carBody->CreateFixture(car.getChassisFixtureDef());
        
}


void OurWorld::initializeJoints()
{
    int indexA, indexB;
    b2Vec2 bodyAAnchorPoint, bodyBAnchorPoint;
    for(auto a:joints)
    {
        indexA = a->getBodyAIndex();
        indexB = a->getBodyBIndex();
        a->initializeDefinition(components[indexA]->dynBody, 
                                components[indexB]->dynBody, 
                                components[indexA]->getRightAnchorPoint(),
                                components[indexB]->getLeftAnchorPoint()
        );
        a->setLinearStiffness(0.0f, 1.0f);
        a->distanceJoint = (b2DistanceJoint*)world.CreateJoint(a->getDistJointDef());
    }
}


void OurWorld::initializeWorld()
{   
    gravity = b2Vec2(0.0f, gravityFactor);
    world.SetGravity(gravity);

    initializeComponents();
    assignFixtures();
    initializeJoints();

}

void OurWorld::destroyB2Bodies()
{
   for(auto a:components)
   {
       world.DestroyBody(a->dynBody);
   }
   components.clear();
   joints.clear();
}


OurComponent OurWorld::getComponent(int index)
{
    return *components[index];
}

void OurWorld::setSimParams(float timeStep_, int32 velocityIterations_, int32 positionIterations_)
{
    this->timeStep = timeStep_;
    this->velocityIterations = velocityIterations_;
    this->positionIterations = positionIterations_;
}

void OurWorld::update()
{
   world.Step(timeStep, velocityIterations, positionIterations);
}