#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "Vector functions.h"

using namespace std;
#define int long long
typedef pair<double,double> pf;
typedef pair<pf,pf> ppd; //{{cartesian x, y},{polar d, angle}}

class ball{
    public:
        double mass = 2;
        double radius = 0.7;
        vec2d v;
};

int32_t main(){
    vec2d vec;
    vec.magnitude = vec.calculateMagnitude(0,0,0);
    ball ball1;
    ball1.v.magnitude = ball1.v.calculateMagnitude(10,0,0);
}