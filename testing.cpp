#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"
#include "Object.h"
#include "Force generator.h"
#include "Vector functions.h"
#include "RK4.h"

using namespace std;
#define int long long
typedef pair<double,double> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

vec2d f (double x, vec2d y){
    return vec2dcreate(0,0,0);
}

int32_t main(){
    /*double x, s = 0.01;
    vec2d y;
    while(x <= 10){//end condition
		x += s;
        double k1y = f(x,vec2dcreate(0,y.first.second,0)).first.second;
	    double k2y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k1y*0.5,0)).first.second;
	    double k3y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k2y*0.5,0)).first.second;
	    double k4y = f(x+s,vec2dcreate(0,y.first.second+s*k3y,0)).first.second;
	    double vy = y.first.second+s/6*(k1y + 2*k2y + 2*k3y +k4y);
		y = vec2dcreate(0,vy,0);
        cout << x << ' ' << y.first.second << "\n";
    }*/
   vec2d v = vec2dcreate(100,0,0);
    ball ball1;
    vec2d weight = vec2dcreate(0,ball1.mass*g,0);
    vec2d air_resistance = vec2dcreate((p*(2*PI*ball1.radius*ball1.radius)*c*v.second.first*v.second.first)/2,angle_add(v.second.second,PI),1);
    vec2d bouyancy = vec2dcreate(-(p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius)),0,0);
    vec2d force = vec2dadd(vec2dadd(weight,air_resistance),bouyancy);
    vec2d ans = vec2ddivide(force,vec2dcreate(ball1.mass,ball1.mass,0));
    cout << v.second.first << ' ' << v.second.second << ' ' << air_resistance.first.first << ' ' << air_resistance.first.second << ' ' << air_resistance.second.first << ' ' << air_resistance.second.second;
    /*double tc, s = 0.0001;
    vec2d vc = vec2dcreate(0,10,0), pc = vec2dcreate(0,0,0);
    while(tc <= 10){//end condition
		tc += s;
		vc = rk4(tc, vc, s, f);
		pc = compound_rk4(tc, vc, pc, s, f);
		cout << vc.first.second << ',' << pc.first.second << "\n"; //output graph axis
    }*/
    /*double s = 0.01, tc = 0;
	vec2d vc = vec2dcreate(100,0,0);
	while(tc <= 10){//end condition
		tc += s;
		vc = rk4(tc, vc, s, fball);
		cout << tc << ',' << vc.first.first << ',' << vc.first.second << ',' << fball(tc,vc).first.first << ',' << fball(tc,vc).first.second << "\n" ; //output graph axis
    }*/
    /*double s = 0.0001, x = 0;
	vec2d y = vec2dcreate(100,0,0);
	while(x <= 10){//end condition
        x += s;
        double k1x = f(x,vec2dcreate(y.first.first,0,0)).first.first;
        double k2x = f(x+0.5 * s,vec2dcreate(y.first.first+s*k1x*0.5,0,0)).first.first;
        double k3x = f(x+0.5 * s,vec2dcreate(y.first.first+s*k2x*0.5,0,0)).first.first;
        double k4x = f(x+s,vec2dcreate(y.first.first+s*k3x,0,0)).first.first;
        double vx = y.first.first+s/6*(k1x + 2*k2x + 2*k3x +k4x);
        cout << fball(x,y).first.first << ' ' << s/6*(k1x + 2*k2x + 2*k3x +k4x) << ' ' << vx << "\n";
    }*/
}