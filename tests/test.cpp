#include "catch2/catch_test_macros.hpp"
#include "../include/OurWorld.hpp"
#include <iostream>

TEST_CASE("static bodies")
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
    j2.setRightBodyStatic();
    j2.setIndexOfBodies(secondBlock.getCompIndex(), secondBlock.getCompIndex());
    world.addJoint(j2);

    Car car = Car();
    car.setUpCar();
    world.addCar(car);

    world.initializeWorld();
    world.setSimParams();
    

    bool isRBConsistent = true;
    bool isLBConsistent = true;

    float eps = 1e-03;

    float LBx = 0;
    float LBy = 0;
    float RBx = 0;
    float RBy= 0;

    for(int i=0; i<100; i++)
    {
        LBx = leftBase.getXCoordinate();
        LBy = leftBase.getYCoordinate();
        RBx = rightBase.getXCoordinate();
        RBy = rightBase.getYCoordinate();
        // std::cout<<"LBase x: "<<LBx<<"   Lbase y: "<<LBy<<std::endl;
        // std::cout<<"RBase x: "<<RBx<<"   Lbase y: "<<RBy<<std::endl;

        if(abs(LBx-0.0f)>eps && abs(LBy - 0.0f)>eps)
        {
            isLBConsistent = false;
        }
         if(abs(RBx-10.0f)>eps && abs(RBy - 0.0f)>eps)
        {
            isRBConsistent = false;
        }

        world.update();
    }

    REQUIRE(isLBConsistent == true);
    REQUIRE(isRBConsistent == true);

}

TEST_CASE("dynamic positions")
{
    OurWorld world = OurWorld();

    StaticComponent leftBase = StaticComponent(0.0f,0.0f);
    leftBase.setUpStaticComponent();
    world.addStaticComponent(leftBase);

    StaticComponent rightBase = StaticComponent(10.0f, 0.0f);
    rightBase.setUpStaticComponent();
    world.addStaticComponent(rightBase);

    OurComponent firstBlock = OurComponent(2.5f,0.0f,4.9f, 0.5f, 10.0f);
    firstBlock.setUpComponent();
    world.addComponent(firstBlock);

    OurComponent secondBlock = OurComponent(7.5f, 0.0f, 4.9f, 0.5f, 10.0f);
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

    float FEx = 0.0;
    float FEy = 0.0;
    float SEx = 0.0;
    float SEy = 0.0;
    for (int i=0; i<100; i++)
    {
        FEx = firstBlock.getXCoordinate();
        FEy = firstBlock.getYCoordinate();
        SEx = secondBlock.getXCoordinate();
        SEy = secondBlock.getYCoordinate();
        
        std::cout<<"First block x: "<<FEx<<"    First block y: "<<FEy<<std::endl;
        std::cout<<"Second block x: "<<SEx<<"    Second block y: "<<SEy<<std::endl;

        world.update();
    }


}