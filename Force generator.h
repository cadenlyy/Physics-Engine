#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"
#include "Object.h"
#include "Vector functions.h"

using namespace std;
#define int long long
#ifndef Force_generator_H_
#define Force_generator_H_
typedef pair<double, double> pd;
typedef pair<pd,pd> vec2d; //{{cartesian x, y},{polar d, angle}}

double fball_y(double t, double v, double d){
    double weight = ball1.mass*g;
    double air_resistance =(p*(2*PI*ball1.radius*ball1.radius)*c*v*v)/2;
    double bouyancy = -(p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius));
    double force = weight+air_resistance+bouyancy;
    return force/ball1.mass;
}
double fball_x(double t, double v, double d){
    double air_resistance =-(p*(2*PI*ball1.radius*ball1.radius)*c*v*v)/2;
    return air_resistance/ball1.mass;
}

double fpendulum(double t, double v, double d){
    return (g*sin(d))/pendulum1.length;
}


#endif