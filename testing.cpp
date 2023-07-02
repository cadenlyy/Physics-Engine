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

int32_t main(){
    cout << fpendulum(0,vec2dcreate(0,1,0),vec2dcreate(10,0,0)).first.second;
}