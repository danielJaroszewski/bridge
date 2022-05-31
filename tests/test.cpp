#include "catch2/catch_test_macros.hpp"
#include "../include/OurWorld.hpp"

TEST_CASE("some")
{
    OurWorld world = OurWorld();
    OurComponent comp1 = OurComponent(0.0f, 1.0f, 4.0f, 5.0f, 10.0f);
    REQUIRE(comp1.getXCoordinate() == 0.0f);
}

TEST_CASE("second")
{
    OurWorld world = OurWorld();
    OurComponent comp1 = OurComponent(0.0f, 1.0f, 4.0f, 5.0f, 10.0f);
    comp1.createBodyDefinition();
    comp1.createBodyFixtureDefinition();
    world.addComponent(comp1);

    OurComponent someComp = world.getComponent(0);
    REQUIRE(someComp.getBodyDef()->position.x == 0.0f);
}

TEST_CASE("World init")
{
    OurWorld world = OurWorld();
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

    REQUIRE(comp1.getBodyDef()->position.x == 0.0f);
}