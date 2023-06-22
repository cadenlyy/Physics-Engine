#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"

using namespace std;
#define int long long
#ifndef Vector_functions_H_
#define Vector_functions_H_

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

vec2d vec2dcreate(float x, float y, bool c){
    if (c == false){
        if(x == 0, y == 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),0}};
        }
        if(x == 0 and y >= 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),0}};
        }
        if(x >= 0 and y == 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI/2}};
        }
        if(x == 0, y <= 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI}};
        }
        if(x <= 0, y == 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI*3/2}};
        }
        if(x > 0 and y > 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),atan(x/y)}};
        }
        if(x > 0 and y < 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI/2-atan(x/y)}};
        }
        if(x < 0 and y < 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI+atan(x/y)}};
        }
        if(x < 0 and y > 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI*3/2-atan(x/y)}};
        }
    }
    return {{x*sin(y),x*cos(y)},{x,y}};
}

vec2d vec2dadd(vec2d x, vec2d y){
    return vec2dcreate(x.first.first+y.first.first,x.first.second+y.first.second,0);
}

vec2d vec2dmulti(vec2d x, vec2d y){
    return vec2dcreate(x.first.first*y.first.first,x.first.second*y.first.second,0);
}
vec2d vec2ddivide(vec2d x, vec2d y){
    return vec2dcreate(x.first.first/y.first.first,x.first.second/y.first.second,0);
}
vec2d vec2dsum(vector <vec2d> v){
    vec2d ans = vec2dcreate(0,0,0);
    for(auto i: v){
        ans = vec2dadd(ans,i);
    }
    return ans;
}

float angle_add(float x, float y){
    if(x+y >= 2*PI){
        return x+y-2*PI;
    }
    return x+y;
}

#endif