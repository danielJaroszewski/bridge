#include "../include/StaticComponent.hpp"

StaticComponent::StaticComponent(float xCoordinate_, float yCoordninate_)
: xCoordinate(xCoordinate_), yCoordinate(yCoordninate_)
{
}

void StaticComponent::createBodyDefinition()
{
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(xCoordinate, yCoordinate);
}