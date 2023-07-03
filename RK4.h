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

double rk4(double x, vector<double> v,double s, double (*f)(double,vector <double>)){
	vector <double> vk1, vk2, vk3, vk4;

	double k1 = f(x,v);
	for(auto i: v) vk1.push_back(i+s*k1*0.5);
	double k2 = f(x+0.5 * s,v);
	for(auto i: v) vk2.push_back(i+s*k2*0.5);
	double k3 = f(x+0.5 * s,vk2);
	for(auto i: v) vk3.push_back(i+s*k3);
	double k4 = f(x+s,vk3);
	double a = v[0]+s/6*(k1 + 2*k2 + 2*k3 +k4);
	return a;
}

double compound_rk4(double x, vector<double> v, double s, double (*f)(double,vector<double>)){
	vector <double> vk1, vk2, vk3, vk4;
	double k1 = rk4(x, v, s, f);
	for(auto i: v) vk1.push_back(i+s*k1*0.5);
	double k2 = rk4(x+0.5 * s, vk1, s, f);
	for(auto i: v) vk2.push_back(i+s*k2*0.5);
	double k3 = rk4(x+0.5 * s, vk2, s, f);
	for(auto i: v) vk3.push_back(i+s*k3);
	double k4 = rk4(x+s, vk3, s, f);
	double a = v[1]+s/6*(k1 + 2*k2 + 2*k3 + k4);
	return a;
}

#endif