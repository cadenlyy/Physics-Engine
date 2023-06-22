#include <bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "Vector functions.h"

using namespace std;
#define int long long
#ifndef RK4_H_
#define RK4_H_

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

vec2d rk4(float x, vec2d y, float s, vec2d (*f)(float,vec2d)){
	//time(x), velocity(y), timestep(s), function of acceleration(f)
	float k1x = f(x,vec2dcreate(y.first.first,0,0)).first.first;
	float k2x = f(x+0.5 * s,vec2dcreate(y.first.first+s*k1x*0.5,0,0)).first.first;
	float k3x = f(x+0.5 * s,vec2dcreate(y.first.first+s*k2x*0.5,0,0)).first.first;
	float k4x = f(x+s,vec2dcreate(y.first.first+s*k3x,0,0)).first.first;
	float vx = y.first.first+s/6*(k1x + 2*k2x + 2*k3x +k4x);

	float k1y = f(x,vec2dcreate(0,y.first.second,0)).first.second;
	float k2y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k1y*0.5,0)).first.second;
	float k3y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k2y*0.5,0)).first.second;
	float k4y = f(x+s,vec2dcreate(0,y.first.second+s*k3y,0)).first.second;
	float vy = y.first.second+s/6*(k1y + 2*k2y + 2*k3y +k4y);
	vec2d v = vec2dcreate(vx,vy,0);
	return v;
}

#endif