#include <bits/stdc++.h>
#include "RK4.cpp"
#include "Force.cpp"
using namespace std;
#define int long long
typedef pair<float, float> pf;

int32_t main() {
	fstream fout;
    fout.open("graph.csv", ios::out | ios::trunc);
	//timestep(h), time(x), velocity(y)
	float h = 0.1, xfinal=55, xc = 0, yc = 0;
	for(int i = 0; i < xfinal/h; i++){
		fout << rk4(xc, yc, h, fball).first << ',' << rk4(xc, yc, h, fball).second<<"\n";
		cout  << ' ' << rk4(xc, yc, h, fball).first << ' ' << rk4(xc, yc, h, fball).second << "\n";
		xc = rk4(xc, yc, h, fball).first;
		yc = rk4(xc, yc, h, fball).second;
    }
}

