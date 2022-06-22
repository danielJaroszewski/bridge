#pragma once

namespace most
{
	class RectPhysicsComponent
	{
	public:
		virtual float getXCoordinate() const = 0;
		virtual float getYCoordinate() const = 0;
		virtual float getWidth() const = 0;
		virtual float getHeight() const = 0;
		virtual float getAngle() const = 0;
	};
}
