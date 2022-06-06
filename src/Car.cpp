#include "../include/Car.hpp"

void Car::createChassisFixtureDef()
{
    vertices[0].Set(-1.5f, -0.5f);
    vertices[1].Set(1.5f, -0.5f);
    vertices[2].Set(1.5f, 0.0f);
    vertices[3].Set(0.0f, 0.9f);
    vertices[4].Set(-1.15f, 0.9f);
    vertices[5].Set(-1.5f, 0.2f);
    chassis.Set(vertices, 6);
}

void Car::setWheelRadius(float radius)
{
    wheel.m_radius = radius;
}

void Car::createBodyDef()
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 1.0f); //to be changed
}

void Car::createWheelFixtureDef()
{
    wheelFixtureDef.shape = &wheel;
    wheelFixtureDef.density = 1.0f;
    wheelFixtureDef.friction = 0.9f;
}