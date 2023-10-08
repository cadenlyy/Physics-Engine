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
typedef pair<pd,pd> ppd; //{{cartesian x, y},{polar d, angle}}

double fball_y(double t, vector<double> v){
    double weight = ball1.mass*g;
    double air_resistance =(p*(2*PI*ball1.radius*ball1.radius)*c*v[0]*v[0])/2;
    double bouyancy = -(p*g*((4/3)*PI*ball1.radius*ball1.radius*ball1.radius));
    double force = weight+air_resistance+bouyancy;
    return force/ball1.mass;
}
double fball_x(double t, vector<double> v){
    double air_resistance =-(p*(2*PI*ball1.radius*ball1.radius)*c*v[0]*v[0])/2;
    return air_resistance/ball1.mass;
}

double fsimple_pendulum(double t, vector<double>v){
    return (g*sin(v[1]))/pendulum1.length;
}

double fdouble_pendulum_1(double t, vector<double>v){
    // v1, p1, a1, v2, p2, a2
    return (-pendulum2.mass2*pendulum2.length2*v[6]*cos(v[1]-v[4])+pendulum2.mass2*pendulum2.length2*v[0]*v[3]*sin(v[1]-v[4])-pendulum2.mass2*pendulum2.length2*pow(v[3],2)*sin(v[1]-v[4])-pendulum2.mass2*pendulum2.length2*v[0]*v[3]*sin(v[1]-v[4])+pendulum2.mass1*g*sin(v[1])+pendulum2.mass2*g*sin(v[1]))/(pendulum2.mass1*pendulum2.length1+pendulum2.mass2*pendulum2.length1);
}

double fdouble_pendulum_2(double t, vector<double>v){
    //v2, p2, a2, v1, p1, a1
    return (-pendulum2.length1*v[5]*cos(v[4]-v[1])+pendulum2.length1*pow(v[3],2)*sin(v[4]-v[1])+g*sin(v[1]))/pendulum2.length2;
}


#endif