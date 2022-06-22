#pragma once
#include "box2d/box2d.h"
#include "Constants.hpp"

/**
 * @brief Static body at far ends of world. Car is supposed to drive from one on the left
 * onto bridge and then drive off onto the right one.
 * Fixed size - 40 x 20
 * Static component should be placed at right or left edge of ledge.
 */
class Ledge
{
private:
	b2Body* b2Ledge;
	float xCoordinate, yCoordinate;
	b2BodyDef ledgeBodyDef;
	b2FixtureDef ledgeFixtureDef;
	b2PolygonShape ledgeBox;

	void createBodyDef();
	void createFixtureDef();
public:
	Ledge(float x, float y);

	void setUpLedge();
	const b2BodyDef* getBodyDef();
	const b2FixtureDef* getFixtureDef();

	float getRightEdgeXCoordinate();
	float getRightEdgeYCoordinate();
	float getLeftEdgeXCoordinate();
	float getLeftEdgeYCoordinate();

	float getCenterX();
	float getCenterY();

	friend class OurWorld;
};
