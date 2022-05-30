#include "include/OurWorld.hpp"
#include "include/Simulation.hpp"
#include <iostream>

using std::cout;

int main(int argc, char const *argv[])
{
    OurWorld world = OurWorld();
    OurComponent comp1 = OurComponent(0.0f,1.0f, 10.0f, 1.0f, 50.0f);
    comp1.createBodyDefinition();
    comp1.createBodyFixtureDefinition();

    OurComponent comp2 = OurComponent(20.0f, 1.0f, 10.0f, 1.0f, 50.0f);
    comp2.createBodyDefinition();
    comp2.createBodyFixtureDefinition();
    world.addComponent(comp1);
    world.addComponent(comp2);

    OurJoint joint1 = OurJoint();
    joint1.setIndexOfBodies(0,1);
    world.addJoint(joint1);

    world.initializeWorld();

    Simulation sim = Simulation();
    //sim.setSimWorld(world);  problem - after passing world by reference got memory leaks caused by destroyB2Bodies() method
    // sim.setSimParams();

    world.destroyB2Bodies();
    cout<<"End of program\n";
    return 0;
}