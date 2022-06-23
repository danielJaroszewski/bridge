#pragma once

//move here all paramters not set by constructors or methods directly

const short DYNAMIC_COMP_CATEGORY = 0x0001;
const short STATIC_COMP_CATEGORY = 0x0002;
const short CAR_CHASSIS_CATEGORY = 0x0004;
const short CAR_WHEELS_CATEGORY = 0x0008;
const short LEDGE_CATEGORY = 0x0010;

const short DYNAMIC_COMP_MASK = CAR_WHEELS_CATEGORY; //collide only with car wheels
const short STATIC_COMP_MASK = 0x0000; //doesn't collide with anything
const short CAR_CHASSIS_MASK = DYNAMIC_COMP_CATEGORY;
const short CAR_WHEELS_MASK = DYNAMIC_COMP_CATEGORY | LEDGE_CATEGORY;
const short LEDGE_MASK = CAR_WHEELS_CATEGORY;

const float TIME_STEP = 1.0f/60.0f;
const int32 VELOCITY_ITERATIONS = 8;
const int32 POSITION_ITERATIONS = 3;




const float CAR_INITIAL_HEIGHT = 10.0F;
const float CAR_WHEEL_RADIUS = 0.4F;
const float CAR_CHASSIS_DENSITY = 1.0F;
const float CAR_CHASSIS_HALF_WIDTH = 1.25F;
const float CAR_CHASSIS_HALF_HEIGHT = 0.75F;
const float CAR_WHEEL_FRICTION = 0.9F;
const float CAR_WHEEL_DENSITY = 1.0F;

const float LEDGE_HALF_WIDTH = 20.0F;
const float LEDGE_HALF_HEIGHT = 10.0F;