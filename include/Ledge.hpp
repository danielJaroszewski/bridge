#include "box2d/box2d.h"
#include "Constants.hpp"
#include "RectPhysicsComponent.hpp"
#pragma once

/**
 * @brief Static body at far ends of world. Car is supposed to drive from one on the left
 * onto bridge and then drive off onto the right one.
 * Fixed size - 40 x 20
 * Static component should be placed at right or left edge of ledge.
 */
class Ledge : public most::RectPhysicsComponent
{
private:
	b2Body* b2Ledge[4]; //multiple bodies becouse box2d does not handle very well  big objects
	float xCoordinate, yCoordinate;
	b2BodyDef ledgeBodyDef[4];
	b2FixtureDef ledgeFixtureDef;
	b2PolygonShape ledgeBox;
	float singleBodyWidth = LEDGE_FULL_WIDTH/4;

	void createBodyDef();
	void createFixtureDef();
public:
	/**
	 * @brief Construct a new Ledge object
	 * 
	 * @param x coordinate of center
	 * @param y coordinate of center
	 */
	Ledge(float x, float y);

	void setUpLedge();
	const b2BodyDef* getBodyDef(int index);
	const b2FixtureDef* getFixtureDef();

	float getRightEdgeXCoordinate();
	float getRightEdgeYCoordinate();
	float getLeftEdgeXCoordinate();
	float getLeftEdgeYCoordinate();

	float getXCoordinate() const override;
	float getYCoordinate() const override;
	float getWidth() const override;
	float getHeight() const override;
	float getAngle() const override;

	friend class OurWorld;
};
