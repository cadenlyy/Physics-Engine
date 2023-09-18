#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "Vector functions.h"

using namespace std;
#define int long long
#ifndef Object_H_
#define Object_H_

typedef pair<double, double> pd;
typedef pair<pd,pd> vec2d; //{{cartesian x, y},{polar d, angle}}

class ball{
    public:
        double mass = 2;
        double radius = 0.7;
        vec2d v = vec2dcreate(10,0,0);
        vec2d pos = vec2dcreate(0,0,0);
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

ball ball1;
simple_pendulum pendulum1;
complex_pendulum pendulum2;

#endif