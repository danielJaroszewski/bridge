#include "OurWorld.hpp"

OurWorld::OurWorld(float gravityFactor_)
:gravityFactor(gravityFactor_)
{    
}

void OurWorld::addComponent(float xCoordinate_, float yCoordinate_, float length_, float width_, float density_)
{
    OurComponent newComponent = OurComponent(xCoordinate_, yCoordinate_, length_, width_, density_);
    components.push_back(newComponent);
}