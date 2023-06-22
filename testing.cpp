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
typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

vec2d f (float x, vec2d y){
    return vec2dadd(vec2dcreate(0,3,0),vec2dcreate(0,-y.first.second,0));
}

int32_t main(){
    float x, s = 0.01;
    vec2d y;
    while(x <= 10){//end condition
		x += s;
        float k1y = f(x,vec2dcreate(0,y.first.second,0)).first.second;
	    float k2y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k1y*0.5,0)).first.second;
	    float k3y = f(x+0.5 * s,vec2dcreate(0,y.first.second+s*k2y*0.5,0)).first.second;
	    float k4y = f(x+s,vec2dcreate(0,y.first.second+s*k3y,0)).first.second;
	    float vy = y.first.second+s/6*(k1y + 2*k2y + 2*k3y +k4y);
		y = vec2dcreate(0,vy,0);
        cout << x << ' ' << y.first.second << "\n";
    }
    /*vec2d v = vec2dcreate(0,-9.78592,0);
    ball ball1;
    vec2d weight = vec2dcreate(ball1.mass*g,0,1);
    vec2d air_resistance = vec2dcreate((p*(2*PI*ball1.radius*ball1.radius)*c*v.second.first*v.second.first)/2,angle_add(v.second.second,PI),1);
    vec2d bouyancy = vec2dcreate(-(p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius)),0,1);
    vec2d force = vec2dadd(vec2dadd(weight,air_resistance),bouyancy);
    vec2d ans = vec2ddivide(force,vec2dcreate(ball1.mass,ball1.mass,0));
    cout << ans.first.second << ' ' << weight.first.second << ' ' << air_resistance.first.second << ' ' << bouyancy.first.second;
    */
}
//fix inverse sin,cos,tan problem