#pragma once
#include "box2d/box2d.h"


class Ib2BodyOwner
{
public:
    virtual b2Body* getB2Body()=0;


};