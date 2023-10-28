#pragma once

#include <vector>
#include <string>

#include "Physics/Vec2d.h"
#include "Physics/constants.h"

class Object {
public:
    vec2d Position;
    vec2d Velocity;
    vec2d Acceleration;
    std::vector <float> VertexPos;
    std::vector <unsigned int> IndexPos;
    float Color[4];
};

class Ball: public Object{
public:
    Ball(ppd Position, ppd Velocity, ppd Acceleration, float Color1, float Color2, float Color3, float Color4, double mass, double radius, int Sides);
    double Mass;
    double Radius;
private:
    int Sides;
    std::vector<float> VertexOfBall(float radius, int Sides);
    std::vector<unsigned int> IndexOfBall(int Count);
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