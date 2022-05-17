#include "../include/OurWorld.hpp"

OurWorld::OurWorld(float gravityFactor_)
:gravityFactor(gravityFactor_)
{    
}

void OurWorld::addComponent(OurComponent component_)
{
    components.push_back(component_);
}

void OurWorld::initialize()
{
    gravity = b2Vec2(0.0f, gravityFactor);
    world.SetGravity(gravity);
    b2BodyDef def;
    for(auto i:components)
    {
        def = i.getBodyDef();
        world.CreateBody(&def);
    }
}