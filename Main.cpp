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
	//timestep(h), time(x), velocity(y)
	double s = 0.01, tc = 0;
	vec2d vc = vec2dcreate(0,0,0), pc = vec2dcreate(0,0,0);
	while(tc <= 10){//end condition
		tc += s;
		vc = rk4(tc, vc, s, fball);
		fout << tc << ',' /*<< vc.first.first << ','*/ << vc.first.second << "\n"; //output graph axis
    }
}

void thrown_ball(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	//timestep(h), time(x), velocity(y)
	double s = 0.0001, tc = 0;
	vec2d vc = vec2dcreate(50,0,0), pc = vec2dcreate(0,0,0);
	while(tc <= 10){//end condition
		tc += s;
		vc = rk4(tc, vc, s, fball);
		pc = compound_rk4(tc, vc, pc, s, fball);
		fout << tc << ',' << vc.first.first << ',' << vc.first.second << ',' << pc.first.first << ',' << pc.first.second << "\n"; //output graph axis
    }
}

int32_t main() {
	thrown_ball();
}

