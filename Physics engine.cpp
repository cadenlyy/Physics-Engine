#include <bits/stdc++.h>
#include "RK4.cpp"
#include "Force.cpp"
using namespace std;
#define int long long
typedef pair<float, float> pf;

void ball_terminal_velocity(){
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	//timestep(h), time(x), velocity(y)
	float h = 0.1, xc = 0, yc = 0;
	while(yc != rk4(xc, yc, h, fball).second){
		fout << rk4(xc, yc, h, fball).first << ',' << rk4(xc, yc, h, fball).second << "\n";
		xc = rk4(xc, yc, h, fball).first;
		yc = rk4(xc, yc, h, fball).second;
    }
}

int32_t main() {
	ball_terminal_velocity();
}

