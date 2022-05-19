#include "include/OurWorld.hpp"
#include <iostream>

using std::cout;

int main(int argc, char const *argv[])
{
    OurWorld world = OurWorld(-10.0f);
    OurComponent comp1 = OurComponent(0.0f,1.0f, 10.0f, 1.0f, 50.0f);
    comp1.createBodyDefinition();
    comp1.createBodyFixtureDefinition();
    world.addComponent(comp1);
    world.initialize();
    world.assignFixtures();
    cout<<"dupa\n";
    return 0;
}