#include "../include/Simulation.hpp"

void Simulation::setSimWorld(const OurWorld& simWorld_)
{
    this->simulationWorld = simWorld_;
}

void Simulation::setSimParams(float timeStep_,int32 velocityIterations_, int32 positionIterations_)
{
    this->timeStep = timeStep_;
    this->velocityIterations = velocityIterations_;
    this->positionIterations = positionIterations_;
}

void Simulation::update()
{
    
}