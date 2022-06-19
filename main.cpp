#include "include/OurWorld.hpp"
#include <iostream>


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
    j1.setIndexOfBodies(leftBase.getCompIndex(), firstBlock.getCompIndex());
    world.addJoint(j1);

    OurJoint j2 = OurJoint();
    j2.setIndexOfBodies(firstBlock.getCompIndex(), secondBlock.getCompIndex());
    world.addJoint(j2);

    OurJoint j3 = OurJoint();
    j3.setRightBodyStatic();
    j3.setIndexOfBodies(secondBlock.getCompIndex(), rightBase.getCompIndex());
    world.addJoint(j3);

    Car car = Car();
    car.setUpCar();
    world.addCar(car);

    world.initializeWorld();
    world.setSimParams();


    world.clearWorld();

    std::cout<<"End of program\n";
    return 0;
}