#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"
#include "Object.h"
#include "Force generator.h"
#include "Vector functions.h"

using namespace std;
#define int long long
typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

int32_t main(){
    ball ball1;
    vec2d v = vec2dcreate(0,0,0);
    vec2d weight = vec2dcreate(ball1.mass*g,0,1);
    vec2d air_resistance = vec2dcreate((p*(2*PI*ball1.radius*ball1.radius)*c*v.second.first*v.second.first)/2,angle_add(v.second.second,180),1);
    vec2d bouyancy = vec2dcreate(-(p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius)),0,1);
    vec2d force = vec2dadd(vec2dadd(weight,air_resistance),bouyancy);
    vec2d ans = vec2dcreate(force.second.first/ball1.mass,force.second.second,1);
    cout << force.first.second << ' ' << ans.first.second << ' ' << ball1.mass << ' ' << force.second.second;
}
//fix inverse sin,cos,tan problem