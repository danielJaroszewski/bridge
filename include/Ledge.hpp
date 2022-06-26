#include "box2d/box2d.h"
#include "Constants.hpp"
#include "RectPhysicsComponent.hpp"
#pragma once

/**
 * Static body at far ends of world. Car is supposed to drive from one on the left
 * onto bridge and then drive off onto the right one.
 * Fixed size specified in the Constants.hpp file
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

	/**
	 * @brief Get coordinates of top left edge. Right base should be placed there
	 * 
	 * @return b2Vec2 Vector containign x and y coordinate
	 */
	b2Vec2 getLeftEdgeCoordiantes(); 

	/**
	 * @brief Get coordinates of top right edge. Left base should be placed there
	 * @return b2Vec2 Vector containign x and y coordinate
	 */
	b2Vec2 getRightEdgeCoordinates();
	/**
	 * @brief X coordinate of the center
	 * 
	 * @return float x of the center
	 */
	float getXCoordinate() const override;

	/**
	 * @brief Y coordinate of the center
	 * 
	 * @return float y of the center
	 */
	float getYCoordinate() const override;

	/**
	 * @brief Get the Width object
	 * 
	 * @return float full width
	 */
	float getWidth() const override;

	/**
	 * @brief Get the Height object
	 * 
	 * @return float full height
	 */
	float getHeight() const override;

	/**
	 * @brief Get the Angle object
	 * 
	 * @return float angle in degrees
	 */
	float getAngle() const override;

	friend class OurWorld;
};
