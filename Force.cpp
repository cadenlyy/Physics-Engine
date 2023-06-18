#include<bits/stdc++.h>
#include "constants.h"
#include "Object.cpp"
using namespace std;
#define int long long

float fball(float t, float V){
    ball ball1;
    cout << (ball1.mass*g-(p*ball1.area*c*V*V)/2-p*g*ball1.volume)/ball1.mass << ' ';
    return (ball1.mass*g-(p*ball1.area*c*V*V)/2-p*g*ball1.volume)/ball1.mass;
}