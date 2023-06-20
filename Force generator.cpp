#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"
#include "Object.cpp"
#include "Vector functions.h"

using namespace std;
#define int long long
typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

float PI = 3.14159265358979323846;

vec2d fball(float D, float V){
    ball ball1;
    vec2d weight = vec2dcreate(ball1.mass*g,180,1);
    vec2d air_resistance = vec2dcreate((p*(2*PI*ball1.radius*ball1.radius)*c*V*V)/2,angle_add(D,180),1);
    vec2d bouyancy = vec2dcreate(-(p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius)),0,1);
    vec2d force = vec2dadd(vec2dadd(weight,air_resistance),bouyancy);
    return vec2dcreate(force.second.first/ball1.mass,force.second.second,1);
}