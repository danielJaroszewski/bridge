#include "../include/Car.hpp"

void Car::createChassisFixtureDef()
{
    vertices[0].Set(-1.5f, -0.5f);
    vertices[1].Set(1.5f, -0.5f);
    vertices[2].Set(1.5f, 0.0f);
    vertices[3].Set(0.0f, 0.9f);
    vertices[4].Set(-1.15f, 0.9f);
    vertices[5].Set(-1.5f, 0.2f);
    chassisPolygon.Set(vertices, 6);
    chassisFixtureDef.shape = &chassisPolygon;
    chassisFixtureDef.density = 1.0f;
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

const b2FixtureDef* Car::getChassisFixtureDef()
{
    return &chassisFixtureDef;
}

const b2FixtureDef* Car::getWheelFixtureDef()
{
    return &wheelFixtureDef;
}

const b2BodyDef* Car::getBodyDef()
{
    return &bodyDef;
}