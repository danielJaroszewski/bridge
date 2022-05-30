#pragma once

#include "OurWorld.hpp"

class Simulation
{
    private:
    OurWorld simulationWorld;
    float timeStep;
    int32 velocityIterations, positionIterations;

    public:
    void setSimWorld(const OurWorld& simWorld_); //to be called after creating all the components and joints - passing world to simulation
    void setSimParams(float timeStep_=(1.0f/60.0f),int32 velocityIterations_=8, int32 positionIterations_ =3); //must be called before starting updating
    void update();

};