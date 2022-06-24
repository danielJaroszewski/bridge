#pragma once
#include "box2d/box2d.h"
#include "Constants.hpp"
#include "Ib2BodyOwner.hpp"

class JoiningPoint : public Ib2BodyOwner
{
private:
    b2CircleShape shape;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2Body* body;
    float x, y;
    int index;
    
    void createFixtureDefinition();
    void createBodyDefinition();
    const b2BodyDef* getBodyDef();
    const b2FixtureDef* getFixtureDef();
    b2Body* getB2Body() override;

public:
    JoiningPoint(float x_, float y_);

    void setUpJoiningPoint();
    float getXCoordinate();
    float getYCoordinate();
    float getRadius();
    void setIndex(int index_);
    int getIndex();
    b2Vec2 getAnchorPoint() override;
   

    friend class OurWorld;

};
