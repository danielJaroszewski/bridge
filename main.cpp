#include "include/OurWorld.hpp"
#include <iostream>

using std::cout;

int main(int argc, char const *argv[])
{
    OurWorld world = OurWorld();

    StaticComponent leftBase = StaticComponent(0.0f,0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);

    StaticComponent rightBase = StaticComponent(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);

    OurComponent firstBlock = OurComponent(2.5f,0.0f,4.9f, 0.5f, 1.0f);
    firstBlock.setUpComponent();
    world.addComponent(firstBlock);

    OurComponent secondBlock = OurComponent(7.5f, 0.0f, 4.9f, 0.5f, 1.0f);
    secondBlock.setUpComponent();
    world.addComponent(secondBlock);

    OurJoint j1 = OurJoint();
    j1.setLeftBodyStatic();
    j1.setIndexOfBodies(0, 0); //first static and first dynamic component
    world.addJoint(j1);

    OurJoint j2 = OurJoint();
    j2.setRightBodyStatic();
    j2.setIndexOfBodies(1,1);
    world.addJoint(j2);

    Car car = Car();
    car.setUpCar();
    world.addCar(car);

    world.initializeWorld();
    world.setSimParams();

    world.update();



    cout<<"End of program\n";
    return 0;
}