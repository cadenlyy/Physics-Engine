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
    Ball(ppd Position, ppd Velocity, ppd Acceleration, float Color1, float Color2, float Color3, float Color4, double Mass, double Radius, int Sides);
    double Mass;
    double Radius;
    int Sides;
    std::vector<float> VertexOfBall(float radius, int Sides);
private:
    std::vector<unsigned int> IndexOfBall(int Count);
};

class Simple_pendulum: public Object{
public:
    Simple_pendulum(ppd AnchorPos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Length, double Angv, double Ang, double Radius, int Sides);
    vec2d AnchorPos;
    double Length;
    double Angv;
    double Ang;
    double Radius;
    int Sides;
    std::vector<float> VertexOfSimplePendulum(float radius, int Sides);
private:
    std::vector<unsigned int> IndexOfSimplePendulum(int Count);
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