#include "OurComponent.hpp"

class OurWorld
{
private:
    float gravityFactor = -10.0f; // to initialize gravity in box2d, default value
public:
    OurWorld(float gravityFactor_);

    // xCoordinate and yCoordinate - coordinates of center of component
    void addComponent(float xCoordinate, float yCoordinate, float length, float width);

    void addJoint(OurComponent bodyA, OurComponent bodyB);

};
