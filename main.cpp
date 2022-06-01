#include "include/OurWorld.hpp"
#include <iostream>

using std::cout;

int main(int argc, char const *argv[])
{
    OurWorld world = OurWorld();

    OurComponent leftBase = OurComponent(1.0f, 1.0f, 50.0f, 10.0f, 50.0f);
    leftBase.createBodyDefinition();
    leftBase.createBodyFixtureDefinition();
    world.addComponent(leftBase);

    OurComponent rightBase = OurComponent(150.0f, 1.0f, 50.0f, 10.0f, 50.0f);
    rightBase.createBodyDefinition();
    rightBase.createBodyFixtureDefinition();
    world.addComponent(rightBase);

    OurComponent comp1 = OurComponent(50.0f, 25.0f, 10.0f, 1.0f, 50.0f);
    comp1.createBodyDefinition();
    comp1.createBodyFixtureDefinition();

    OurComponent comp2 = OurComponent(65.0f, 25.0f, 10.0f, 1.0f, 50.0f);
    comp2.createBodyDefinition();
    comp2.createBodyFixtureDefinition();
    world.addComponent(comp1);
    world.addComponent(comp2);

    OurJoint joint1 = OurJoint();
    joint1.setIndexOfBodies(0,1);
    world.addJoint(joint1);

    world.initializeWorld();

    world.setSimParams();
    world.update();

    world.destroyB2Bodies();
    cout<<"End of program\n";
    return 0;
}