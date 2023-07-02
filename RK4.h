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

double rk4(double x, double y, double z,double s, double (*f)(double,double,double)){
	//time(x), velocity(y), timestep(s), function of acceleration(f)
	double k1 = f(x,y,z);
	double k2 = f(x+0.5 * s,y+s*k1*0.5,z+s*k1*0.5);
	double k3 = f(x+0.5 * s,y+s*k2*0.5,z+s*k2*0.5);
	double k4 = f(x+s,y+s*k3,z+s*k3);
	double v = y+s/6*(k1 + 2*k2 + 2*k3 +k4);
	return v;
}

double compound_rk4(double x, double y, double z, double s, double (*f)(double,double,double)){
	double k1 = rk4(x, y, z, s, f);
	double k2 = rk4(x+0.5 * s,y+s*k1*0.5, z+s*k1*0.5, s, f);
	double k3 = rk4(x+0.5 * s,y+s*k2*0.5, z+s*k2*0.5, s, f);
	double k4 = rk4(x+s,y+s*k3, z+s*k3, s, f);
	double v = z+s/6*(k1 + 2*k2 + 2*k3 + k4);
	return v;
}

#endif