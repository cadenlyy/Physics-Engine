#pragma once

#include "Vec2d.h"
#include "constants.h"

class ball{
public:
    double mass;
    double radius;
    vec2d v;
    vec2d pos;
};

class simple_pendulum{
public:
    double length = 2;
    double angv = 0;
    double ang = PI/18*3.3;
    vec2d pos;
};
class complex_pendulum{
public:
    double mass1 = 2;
    double length1 = 2;
    double anga1 = 0;
    double angv1 = 0;
    double ang1 = PI/18*3;
    vec2d pos1;
    double mass2 = 2;
    double length2 = 2;
    double anga2 = 0;
    double angv2 = 0;
    double ang2 = PI/18*3;
    vec2d pos2;
};