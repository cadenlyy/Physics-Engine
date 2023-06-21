#include <bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "RK4.h"
#include "Force generator.h"
#include "Object.h"
#include "constants.h"

using namespace std;
#define int long long

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

void ball_terminal_velocity(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	//timestep(h), time(x), velocity(y)
	float s = 0.1, tc = 0;
	vec2d vc = vec2dcreate(0,0,0), pc = vec2dcreate(0,0,0);
	while(tc <= 50.0){//end condition
		tc += s;
		vc = rk4(tc, vc, s, fball);
		fout << tc << ',' << vc.first.first << "\n"; //output graph axis
    }
}

int32_t main() {
	ball_terminal_velocity();
}

