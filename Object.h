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

class pendulum{
    public:
        double length = 2;
        double angv = 0;
        double ang = PI/2;
        vec2d pos;
};

ball ball1;
pendulum pendulum1;

#endif