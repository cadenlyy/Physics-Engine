#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"
#include "Object.cpp"

using namespace std;
#define int long long

typedef pair<float,float> pf;
typedef pair<pf,pf> vec2d; //{{cartesian x, y},{polar d, angle}}

float PI = 3.14159265358979323846;

float fball(float t, float V){
    ball ball1;
    return (ball1.mass*g-(p*(2*PI*ball1.radius*ball1.radius)*c*V*V)/2-p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius))/ball1.mass;
}

int32_t main(){
    ball ball1;
    float V = 0;
    cout << fball(0,V) << "\n";
    cout << ball1.mass*g << ' ' << -(p*(2*PI*ball1.radius*ball1.radius)*c*V*V)/2 << ' ' << -p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius);
}