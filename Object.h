#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "Vector functions.h"

using namespace std;
#define int long long
#ifndef Object_H_
#define Object_H_

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

class ball{
    public:
        float mass = 0.2;
        float radius = 0.05;
};
#endif