#include "./OurComponent.hpp"
#include "../box2d/include/box2d/box2d.h"
#include <vector>

using std::vector;

class OurWorld
{
private:
    float gravityFactor = -10.0f; // to initialize gravity in box2d, default value
    vector<OurComponent> components;
public:
    OurWorld(float gravityFactor_);

    // xCoordinate and yCoordinate - coordinates of center of component
    void addComponent(float xCoordinate, float yCoordinate, float length, float width, float density);

    void addJoint(OurComponent bodyA, OurComponent bodyB);
    void initialize(); //making box2d world and box2d bodies

};
