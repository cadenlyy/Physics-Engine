#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

using namespace std;
#define int long long

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

vec2d vec2dcreate(float x, float y, bool c){
    if (c == false){
        if(x == 0 and y == 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),-1}};
        }
        if(y == 0){
            return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),0}};
        }
        return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),atan(x/y)}};
    }
    if(y == -1){
        return {{x*sin(0),x*cos(0)},{x,y}};
    }
    return {{x*sin(y),x*cos(y)},{x,y}};
}

vec2d vec2dadd(vec2d x, vec2d y){
    return vec2dcreate(x.first.first+y.first.first,x.first.second+y.first.second);
}

float angle_add(float x, float y){
    if(x+y >= 360){
        return x+y-360;
    }
    return x+y;
}