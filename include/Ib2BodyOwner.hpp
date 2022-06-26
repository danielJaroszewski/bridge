#pragma once
#include "box2d/box2d.h"

/**
 * @brief Interface implemented by dynamic and static components. Created mainly for generalizing joints creation
 * 
 */
class Ib2BodyOwner
{
public:
    virtual b2Body* getB2Body()=0;
    virtual b2Vec2 getAnchorPoint()=0;

};