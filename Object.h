#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "Vector functions.h"

using namespace std;
#define int long long
#ifndef Object_H_
#define Object_H_

typedef pair<double, double> pd;
typedef pair<pd,pd> vec2d; //{{cartesian x, y},{polar d, angle}}

class ball{
    public:
        double mass = 2;
        double radius = 0.8;
};
#endif