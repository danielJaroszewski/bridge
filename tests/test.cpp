#include "catch2/catch_test_macros.hpp"
#include "../include/OurWorld.hpp"


TEST_CASE("World init")
{
    OurWorld world;
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

    world.initializeWorld();

    REQUIRE(comp1.getXCoordinate() == 0.0f);
}

TEST_CASE("positions")
{
    OurWorld world;
    OurComponent comp1 = OurComponent(0.0f, 10.0f, 1.0f, 0.1f, 10.0f);
    comp1.createBodyDefinition();
    comp1.createBodyFixtureDefinition();
    world.addComponent(comp1);
    world.initializeWorld();

    float comp1X= comp1.getXCoordinate();
    float comp1Y = comp1.getYCoordinate();

    REQUIRE(comp1X==0.0f);
    REQUIRE(comp1Y==10.0f);
}