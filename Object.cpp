#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "Vector functions.h"

using namespace std;
#define int long long

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

class ball{
    public:
        float mass = 0.2;
        vec2d p = vec2dcreate(0,0,0);
        vec2d v = vec2dcreate(0,0,1);
        float radius = 0.05;
};
