#include <bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "RK4.h"
#include "Force generator.h"
#include "Object.h"
#include "constants.h"

using namespace std;
#define int long long

typedef pair<double, double> pd;
typedef pair<pd,pd> vec2d; //{{cartesian x, y},{polar d, angle}}

void ball_terminal_velocity(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	double s = 0.01, tc = 0;
	vector <double> v = {ball1.v.first.second};
	while(ball1.v.first.second != rk4(tc, v, s,fball_y)){//end condition
		tc += s;
		v = {ball1.v.first.second};
		ball1.v.first.second = rk4(tc, v, s, fball_y);
		//ball1.pos = compound_rk4(tc, ball1.v, ball1.pos, s, fball);
		fout << tc << ',' << ball1.v.first.first << ',' << ball1.v.first.second << "\n"; //output graph axis
    }
}

void thrown_ball(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	double s = 0.0001, tc = 0;
	vector<double>v;
	while(tc <= 10){//end condition
		tc += s;
		v = {ball1.v.first.first};
		ball1.v.first.first = rk4(tc, v, s, fball_x);
		v = {ball1.v.first.second};
		ball1.v.first.second = rk4(tc, v, s, fball_y);
		v = {ball1.v.first.first, ball1.pos.first.first};
		ball1.pos.first.first = compound_rk4(tc, v, s, fball_x);
		v = {ball1.v.first.second, ball1.pos.first.second};
		ball1.pos.first.second = compound_rk4(tc, v, s, fball_y);
		fout << tc << ',' << ball1.v.first.first << ',' << ball1.v.first.second << ',' << ball1.pos.first.first << ',' << ball1.pos.first.second << "\n"; //output graph axis
    }
}

void single_pendulum(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	double s = 0.0001, tc = 0;
	vector<double>v;
	while(tc <= 10){//end condition
		tc += s;
		v = {pendulum1.angv, pendulum1.ang};
		pendulum1.angv = rk4(tc, v, s, fsimple_pendulum);
		v = {pendulum1.angv, pendulum1.ang};
		pendulum1.ang = compound_rk4(tc, v, s, fsimple_pendulum);
		pendulum1.pos = vec2dcreate(pendulum1.length,PI-pendulum1.ang,1);
		fout << tc << ',' << pendulum1.angv << ',' << pendulum1.ang << ',' << pendulum1.pos.first.first << ',' << pendulum1.pos.first.second << "\n"; //output graph axis
    }
}

void double_pendulum(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	double s = 0.0001, tc = 0;
	vector<double>v;
	while(tc <= 10){//end condition
		tc += s;
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.anga1 = fdouble_pendulum_1(tc,v);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.anga2 = fdouble_pendulum_2(tc,v);
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.angv1 = rk4(tc, v, s, fdouble_pendulum_1);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.angv2 = rk4(tc, v, s, fdouble_pendulum_2);
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.ang1 = compound_rk4(tc, v, s, fdouble_pendulum_1);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.ang2 = compound_rk4(tc, v, s, fdouble_pendulum_2);
		pendulum2.pos1 = vec2dcreate(pendulum2.length1,PI-pendulum2.ang1,1);
		pendulum2.pos2 = vec2dcreate(pendulum2.pos1.first.first+pendulum2.length2*sin(pendulum2.ang2),pendulum2.pos1.first.second-pendulum2.length2*cos(pendulum2.ang2),0);
		fout << tc << ',' << pendulum2.angv1 << ','  << pendulum2.angv2 << ',' << pendulum2.ang1 << ',' << pendulum2.ang2 << ',' << pendulum2.pos1.first.first << ',' << pendulum2.pos1.first.second << ',' << pendulum2.pos2.first.first << ',' << pendulum2.pos2.first.second << "\n"; //output graph axis
    }
}

int32_t main() {
	double_pendulum();
}

