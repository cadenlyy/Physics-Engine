#include <bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "Vector functions.h"

using namespace std;
#define int long long
#ifndef RK4_H_
#define RK4_H_

typedef pair<double, double> pd;
typedef pair<pd,pd> vec2d; //{{cartesian x, y},{polar d, angle}}

vec2d rk4(double x, vec2d y, double s, vec2d (*f)(double,vec2d)){
	//time(x), velocity(y), timestep(s), function of acceleration(f)
	double k1x = f(x,vec2dcreate(y.first.first,0,0)).first.first;
	double k2x = f(x+0.5 * s,vec2dcreate(y.first.first+s*k1x*0.5,0,0)).first.first;
	double k3x = f(x+0.5 * s,vec2dcreate(y.first.first+s*k2x*0.5,0,0)).first.first;
	double k4x = f(x+s,vec2dcreate(y.first.first+s*k3x,0,0)).first.first;
	double vx = y.first.first+s/6*(k1x + 2*k2x + 2*k3x +k4x);

	double k1y = f(x,vec2dcreate(0,y.first.second,0)).first.second;
	double k2y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k1y*0.5,0)).first.second;
	double k3y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k2y*0.5,0)).first.second;
	double k4y = f(x+s,vec2dcreate(0,y.first.second+s*k3y,0)).first.second;
	double vy = y.first.second+s/6*(k1y + 2*k2y + 2*k3y +k4y);
	vec2d v = vec2dcreate(vx,vy,0);
	return v;
}

vec2d compound_rk4(double x, vec2d y, vec2d z, double s, vec2d (*f)(double,vec2d)){
	double k1x = rk4(x,vec2dcreate(y.first.first,0,0), s, f).first.first;
	double k2x = rk4(x+0.5 * s,vec2dcreate(y.first.first+s*k1x*0.5,0,0), s, f).first.first;
	double k3x = rk4(x+0.5 * s,vec2dcreate(y.first.first+s*k2x*0.5,0,0), s, f).first.first;
	double k4x = rk4(x+s,vec2dcreate(y.first.first+s*k3x,0,0), s, f).first.first;
	double vx = z.first.first+s/6*(k1x + 2*k2x + 2*k3x +k4x);

	double k1y = rk4(x,vec2dcreate(0,y.first.second,0), s, f).first.second;
	double k2y = rk4(x+0.5 * s,vec2dcreate(0,y.first.second+s*k1y*0.5,0), s, f).first.second;
	double k3y = rk4(x+0.5 * s,vec2dcreate(0,y.first.second+s*k2y*0.5,0), s, f).first.second;
	double k4y = rk4(x+s,vec2dcreate(0,y.first.second+s*k3y,0), s, f).first.second;
	double vy = z.first.second+s/6*(k1y + 2*k2y + 2*k3y +k4y);
	vec2d v = vec2dcreate(vx,vy,0);
	return v;
}

#endif