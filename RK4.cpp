#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<float, float> pf;

pf rk4(float x, float y, float s, float (*f)(float,float)){
	//time(x), velocity(y), timestep(s), function of acceleration(f)
	float k1 = f(x,y);
	float k2 = f(x+0.5 * s,y+0.5 * k1 * s);
	float k3 = f(x+0.5 * s,y+0.5 * k2 * s);
	float k4 = f(x+s,y+k3 * s);
	//cout  << x+s  << ' ' << y+(k1+2 * k2+2 * k3+k4)/6*s << "\n";
	pf p {x+s,y+(k1+2 * k2+2 * k3+k4)/6*s};
	return p;
}