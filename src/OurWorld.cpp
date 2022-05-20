#include "../include/OurWorld.hpp"
#include <iostream>

OurWorld::OurWorld(float gravityFactor_)
:gravityFactor(gravityFactor_)
{    
}

void OurWorld::addComponent(OurComponent& component_)
{
    components.push_back(component_);
}

void OurWorld::addJoint(OurJoint& joint_)
{
    joints.push_back(joint_);
}

void OurWorld::initializeComponents()
{
    gravity = b2Vec2(0.0f, gravityFactor);
    world.SetGravity(gravity);
    b2BodyDef bodyDef;
    for(auto i:components)
    {
        bodyDef = i.getBodyDef();
        try
        {
            b2Bodies.push_back(world.CreateBody(&bodyDef));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}

void OurWorld::assignFixtures()
{
    b2FixtureDef fixDef;
    for(int i=0; i<b2Bodies.size(); i++)
    {
        try
        {
            fixDef = components[i].getFixtureDefinition();
            b2Bodies[i]->CreateFixture(&fixDef);
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
    for(auto a:joints)
    {
        indexA = a.getBodyAIndex();
        indexB = a.getBodyBIndex();

        a.initializeDefinition(b2Bodies[indexA], b2Bodies[indexB], b2Bodies[indexA]->GetWorldCenter(), b2Bodies[indexB]->GetWorldCenter());
        a.setLinearStiffness(0.0f, 1.0f);
    }
}

void OurWorld::destroyB2BodiesAndJoints()
{
    for(auto a : b2Bodies)
    {
        world.DestroyBody(a);
    }

    for(auto i: b2Joints)
    {
        world.DestroyJoint(i);
    }

}