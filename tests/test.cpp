#include "catch2/catch_test_macros.hpp"
#include "../include/OurWorld.hpp"

TEST_CASE("some")
{
    OurWorld world = OurWorld(-10.0f);
    OurComponent comp1 = OurComponent(0.0f, 1.0f, 4.0f, 5.0f, 10.0f);
    REQUIRE(comp1.getXCoordinate() == 0.0f);
}