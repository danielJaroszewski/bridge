#pragma once

#include "OurWorld.hpp"

class Simulation
{
    private:
    OurWorld simulationWorld;


    public:
    void setSimWorld(OurWorld& simWorld_); //to be called after creating all the components and joints - passing world to simulation
    void update();

};