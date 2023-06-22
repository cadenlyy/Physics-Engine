#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"
#include "Object.h"
#include "Vector functions.h"

using namespace std;
#define int long long
#ifndef Force_generator_H_
#define Force_generator_H_
typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

vec2d fball(float t, vec2d v){
    ball ball1;
    vec2d weight = vec2dcreate(ball1.mass*g,0,1);
    vec2d air_resistance = vec2dcreate((p*(2*PI*ball1.radius*ball1.radius)*c*v.second.first*v.second.first)/2,angle_add(v.second.second,PI),1);
    vec2d bouyancy = vec2dcreate(-(p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius)),0,1);
    vec2d force = vec2dadd(vec2dadd(weight,air_resistance),bouyancy);
    return vec2ddivide(force,vec2dcreate(ball1.mass,ball1.mass,0));
}

#endif