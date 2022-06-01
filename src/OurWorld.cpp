#include "../include/OurWorld.hpp"
#include <iostream>

void OurWorld::addComponent(OurComponent& component_)
{
    components.push_back(&component_);
}

void OurWorld::addJoint(OurJoint& joint_)
{
    joints.push_back(&joint_);
}

void OurWorld::initializeComponents()
{
    gravity = b2Vec2(0.0f, gravityFactor);
    world.SetGravity(gravity);
    for(auto i:components)
    {
        try
        {
            i->dynBody = world.CreateBody(i->getBodyDef());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}


void OurWorld::assignFixtures()
{
    for(auto i :components)
    {
        try
        {
            i->dynBody->CreateFixture(i->getFixtureDefinition());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }     
    }
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