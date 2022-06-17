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

void Car::createChassisBodyDef()
{
    chassisBodyDef.type = b2_dynamicBody;
    chassisBodyDef.position.Set(0.0f, 1.0f); // to be changed
}

void Car::createWheel1BodyDef()
{
    wheel1BodyDef.type = b2_dynamicBody;
    wheel1BodyDef.position.Set(-1.0f, 0.35f);
}

void Car::createWheel2BodyDef()
{
    wheel2BodyDef.type = b2_dynamicBody;
    wheel2BodyDef.position.Set(1.0f, 0.4f);
}

void Car::createWheelFixtureDef()
{
    wheelFixtureDef.shape = &wheel;
    wheelFixtureDef.density = 1.0f;
    wheelFixtureDef.friction = 0.9f;
}

void Car::setUpCar()
{
    createChassisFixtureDef();
    createChassisBodyDef();
    createWheelFixtureDef();
    createWheel1BodyDef();
    createWheel2BodyDef();
}

void Car::createJointDef()
{
    b2Vec2 axis(0.0f, 1.0f);
    float wheelMass = 2.51f;
    float hertz = 4.0f;
    float dampingRatio = 0.7f;
    float omega = 2.0f * b2_pi * hertz;

    wheel1JointDef.Initialize(chassisBody, wheel1Body, wheel1Body->GetPosition(), axis);
    wheel1JointDef.motorSpeed = 0.0f;
    wheel1JointDef.maxMotorTorque = 10.0f;
    wheel1JointDef.enableMotor = false;
    wheel1JointDef.stiffness = wheelMass * omega * omega;
    wheel1JointDef.damping = 2.0f * wheelMass * dampingRatio * omega;
    wheel1JointDef.lowerTranslation = -0.25f;
    wheel1JointDef.upperTranslation = 0.25f;
    wheel1JointDef.enableLimit = true;
    
    wheel2JointDef.Initialize(chassisBody, wheel2Body, wheel2Body->GetPosition(), axis);
    wheel2JointDef.motorSpeed = 0.0f;
    wheel2JointDef.maxMotorTorque = 10.0f;
    wheel2JointDef.enableMotor = false;
    wheel2JointDef.stiffness = wheelMass * omega * omega;
    wheel2JointDef.damping = 2.0f * wheelMass * dampingRatio * omega;
    wheel2JointDef.lowerTranslation = -0.25f;
    wheel2JointDef.upperTranslation = 0.25f;
    wheel2JointDef.enableLimit = true;

}

const b2FixtureDef *Car::getChassisFixtureDef()
{
    return &chassisFixtureDef;
}

const b2FixtureDef *Car::getWheelFixtureDef()
{
    return &wheelFixtureDef;
}

const b2BodyDef *Car::getChassisBodyDef()
{
    return &chassisBodyDef;
}

const b2BodyDef *Car::getWheel1BodyDef()
{
    return &wheel1BodyDef;
}

const b2BodyDef *Car::getWheel2BodyDef()
{
    return &wheel2BodyDef;
}

const b2WheelJointDef* Car::getWheel1JointDef()
{
    return &wheel1JointDef;
}

const b2WheelJointDef* Car::getWheel2JointDef()
{
    return &wheel2JointDef;
}
