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

void OurWorld::initialize()
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
    for(int i=0; i<components.size(); i++)
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

void OurWorld::destroyB2World()
{

}