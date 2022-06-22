#include "../../include/Graphics/CarVisuals.hpp"

#include "../../include/Constants.hpp"

namespace most
{
	CarVisuals::CarVisuals(Car& in)
		: car(in)
	{
		rect.setFillColor(sf::Color::Green);
		leftWheel.setFillColor(sf::Color::Red);
		rightWheel.setFillColor(sf::Color::Red);

		rect.setSize(sf::Vector2f(CAR_CHASSIS_HALF_WIDTH * 2.0f, CAR_CHASSIS_HALF_HEIGHT * 2.0f));
		leftWheel.setRadius(CAR_WHEEL_RADIUS);
		rightWheel.setRadius(CAR_WHEEL_RADIUS);
	}

	void CarVisuals::physicsUpdate()
	{
		leftWheel.setPosition(car.getLeftWheelXCoordinate(), car.getLeftWheelYCoordinate());
		rightWheel.setPosition(car.getRightWheelXCoordinate(), car.getRightWheelYCoordinate());
		rect.setPosition(car.getChassisXCoordinate(), car.getChassisYCoordinate());
		rect.setRotation(car.getChassisAngle());
	}

	void CarVisuals::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(rect, states);
		target.draw(leftWheel, states);
		target.draw(rightWheel, states);
	}
}
