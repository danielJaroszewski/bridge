#include "../include/Car.hpp"

void Car::createChassisFixtureDef()
{
    chassisPolygon.SetAsBox(CAR_CHASSIS_HALF_WIDTH, CAR_CHASSIS_HALF_HEIGHT);
    chassisFixtureDef.shape = &chassisPolygon;
    chassisFixtureDef.density = CAR_CHASSIS_DENSITY;
    chassisFixtureDef.filter.categoryBits = CAR_CHASSIS_CATEGORY;
    chassisFixtureDef.filter.maskBits = CAR_CHASSIS_MASK;
}

void Car::setWheelRadius(float radius)
{
    wheel.m_radius = radius;
}

void Car::createChassisBodyDef()
{
    chassisBodyDef.type = b2_dynamicBody;
    chassisBodyDef.position.Set(0.0f, 1.0f+CAR_INITIAL_HEIGHT);
}

void Car::createWheel1BodyDef()
{
    wheel1BodyDef.type = b2_dynamicBody;
    wheel1BodyDef.position.Set(-1.0f, 0.35f+CAR_INITIAL_HEIGHT);
}

void Car::createWheel2BodyDef()
{
    wheel2BodyDef.type = b2_dynamicBody;
    wheel2BodyDef.position.Set(1.0f, 0.4f+CAR_INITIAL_HEIGHT);
}

void Car::createWheelFixtureDef()
{
    wheelFixtureDef.shape = &wheel;
    wheelFixtureDef.density = CAR_WHEEL_DENSITY;
    wheelFixtureDef.friction = CAR_WHEEL_FRICTION;
    wheelFixtureDef.filter.categoryBits = CAR_WHEELS_CATEGORY;
    wheelFixtureDef.filter.maskBits = CAR_WHEELS_MASK;
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

const b2FixtureDef *Car::getChassisFixtureDef() const
{
    return &chassisFixtureDef;
}

const b2FixtureDef *Car::getWheelFixtureDef() const
{
    return &wheelFixtureDef;
}

const b2BodyDef *Car::getChassisBodyDef() const
{
    return &chassisBodyDef;
}

const b2BodyDef *Car::getWheel1BodyDef() const
{
    return &wheel1BodyDef;
}

const b2BodyDef *Car::getWheel2BodyDef() const
{
    return &wheel2BodyDef;
}

const b2WheelJointDef* Car::getWheel1JointDef() const
{
    return &wheel1JointDef;
}

const b2WheelJointDef* Car::getWheel2JointDef() const
{
    return &wheel2JointDef;
}

float Car::getChassisXCoordinate() const
{
    return chassisBody->GetPosition().x;
}

float Car::getChassisYCoordinate() const
{
    return chassisBody->GetPosition().y;
}

float Car::getLeftWheelXCoordinate() const
{
    return wheel1Body->GetPosition().x;
}

float Car::getLeftWheelYCoordinate() const
{
    return wheel1Body->GetPosition().y;
}

float Car::getRightWheelXCoordinate() const
{
    return wheel2Body->GetPosition().x;
}

float Car::getRightWheelYCoordinate() const
{
    return wheel2Body->GetPosition().y;
}

float Car::getChassisAngle() const
{
    return chassisBody->GetAngle();
}

float Car::getLeftWheelAngle() const
{
    return wheel1Body->GetAngle();
}

float Car::getRightWheelAngle() const
{
    return wheel2Body->GetAngle();
}
