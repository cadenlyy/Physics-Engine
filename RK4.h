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
	vec2d k1 = f(x,y);
	vec2d k2 = f(x+0.5 * s,vec2dadd(y,vec2dmulti(vec2dcreate(0.5*s,0.5*s,0),k1)));
	vec2d k3 = f(x+0.5 * s,vec2dadd(y,vec2dmulti(vec2dcreate(0.5*s,0.5*s,0),k2)));
	vec2d k4 = f(x+s,vec2dadd(y,vec2dmulti(vec2dcreate(s,s,0),k3)));
	vector <vec2d> ans = {y,k1,vec2dmulti(k2,vec2dcreate(2,2,0)),vec2dmulti(k3,vec2dcreate(2,2,0)),k4};
	vec2d v = vec2dmulti(vec2dsum(ans),vec2dcreate(s/6,s/6,0));
	return v;
}

#endif