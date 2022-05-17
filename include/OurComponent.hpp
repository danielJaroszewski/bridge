#include "../box2d/include/box2d/box2d.h"

class OurComponent
{
private:
    float xCoordinate;
    float yCoordinate;
    float length;
    float width;
    float density;
    b2BodyDef bodyDef;

public:
    OurComponent(float xCoordinate_, float yCoordinate_, float length_, float width_, float density_);

    void createBodyDefinition();
    b2BodyDef getBodyDef();

};