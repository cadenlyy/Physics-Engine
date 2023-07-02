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
	while(ball1.v.first.second != rk4(tc, ball1.v.first.second, ball1.pos.first.second, s,fball_y)){//end condition
		tc += s;
		ball1.v.first.second = rk4(tc, ball1.v.first.second, ball1.pos.first.second, s, fball_y);
		//ball1.pos = compound_rk4(tc, ball1.v, ball1.pos, s, fball);
		fout << tc << ',' << ball1.v.first.first << ',' << ball1.v.first.second << "\n"; //output graph axis
    }
}

void thrown_ball(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	double s = 0.0001, tc = 0;
	while(tc <= 10){//end condition
		tc += s;
		ball1.v.first.first = rk4(tc, ball1.v.first.first, ball1.pos.first.first, s, fball_x);
		ball1.v.first.second = rk4(tc, ball1.v.first.second, ball1.pos.first.second, s, fball_y);
		ball1.pos.first.first = compound_rk4(tc, ball1.v.first.first, ball1.pos.first.first, s, fball_x);
		ball1.pos.first.second = compound_rk4(tc, ball1.v.first.second, ball1.pos.first.second, s, fball_y);
		fout << tc << ',' << ball1.v.first.first << ',' << ball1.v.first.second << ',' << ball1.pos.first.first << ',' << ball1.pos.first.second << "\n"; //output graph axis
    }
}

void single_pendulum(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	double s = 0.00001, tc = 0;
	while(tc <= 10){//end condition
		tc += s;
		pendulum1.angv = rk4(tc, pendulum1.angv, pendulum1.pos.second.second, s, fpendulum);
		pendulum1.ang = compound_rk4(tc, pendulum1.angv, pendulum1.ang, s, fpendulum);
		pendulum1.pos = vec2dcreate(pendulum1.length,PI-pendulum1.ang,1);
		fout << tc << ',' << pendulum1.angv << ',' << pendulum1.ang << ',' << pendulum1.pos.first.first << ',' << pendulum1.pos.first.second << "\n"; //output graph axis
    }
}

int32_t main() {
	single_pendulum();
}

