#include "include/OurWorld.hpp"
#include <iostream>

using std::cout;

int main(int argc, char const *argv[])
{
    OurWorld world = OurWorld(-10.0f);
    OurComponent comp1 = OurComponent(0.0f,1.0f, 10.0f, 1.0f, 50.0f);
    comp1.createBodyDefinition();
    comp1.createBodyFixtureDefinition();

    OurComponent comp2 = OurComponent(15.0f, 1.0f, 10.0f, 1.0f, 50.0f);
    comp2.createBodyDefinition();
    comp2.createBodyFixtureDefinition();
    world.addComponent(comp1);
    world.addComponent(comp2);

    OurJoint joint1 = OurJoint();
    joint1.setIndexOfBodies(0,1);

    world.initializeComponents();
    world.assignFixtures();
    world.initializeJoints();

    world.destroyB2BodiesAndJoints();
    cout<<"dupa\n";
    return 0;
}