#include "../include/OurWorld.hpp"

OurWorld::OurWorld(float gravityFactor_)
:gravityFactor(gravityFactor_)
{    
}

void OurWorld::addComponent(float xCoordinate_, float yCoordinate_, float length_, float width_, float density_)
{
    OurComponent newComponent = OurComponent(xCoordinate_, yCoordinate_, length_, width_, density_);
    components.push_back(newComponent);
}

void OurWorld::initialize()
{
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    b2BodyDef def;
    for(auto i:components)
    {
        def = i.getBodyDef();
        world.CreateBody(&def);
    }
}