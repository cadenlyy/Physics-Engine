#include <bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "RK4.cpp"
#include "Force generator.cpp"
#include "Vector functions.h"
#include "Object.cpp"
#include "constants.h"

using namespace std;
#define int long long

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

void ball_terminal_velocity(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	//timestep(h), time(x), velocity(y)
	float s = 0.1, tc = 0, vc = 0, xc = 0, yc = 0;
	while(vc != rk4(tc, vc, s, fball).second){
		fout << rk4(tc, vc, s, fball).first << ',' << rk4(tc, vc, s, fball).second << "\n";
		tc = rk4(tc, vc, s, fball).first;
		vc = rk4(tc, vc, s, fball).second;
    }
}

int32_t main() {
	ball_terminal_velocity();
}

