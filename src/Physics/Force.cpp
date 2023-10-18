#include <vector>

#include "Force.h"
#include "constants.h"
#include "Objects.h"

double fball_y(double t, std::vector<double> v, ball* Ball1) {
    ball ball1 = *Ball1;
    double weight = ball1.mass * g;
    double air_resistance = (p * (2 * PI * ball1.radius * ball1.radius) * c * v[0] * v[0]) / 2;
    double bouyancy = -(p * g * ((4 / 3) * PI * ball1.radius * ball1.radius * ball1.radius));
    double force = weight + air_resistance + bouyancy;
    return force / ball1.mass;
}

double  fball_x(double t, std::vector<double> v, ball* ball1) {
    ball ball1 = *Ball1;
    double air_resistance = -(p * (2 * PI * ball1.radius * ball1.radius) * c * v[0] * v[0]) / 2;
    return air_resistance / ball1.mass;
}

double  fsimple_pendulum(double t, std::vector<double>v, simple_pendulum* Pendulum1) {
    simple_pendulum pendulum1 = *Pendulum1;
    return (g * sin(v[1])) / pendulum1.length;
}

double fdouble_pendulum_1(double t, std::vector<double>v, complex_pendulum* Pendulum2) {
    // v1, p1, a1, v2, p2, a2
    complex_pendulum pendulum2 = *Pendulum2;
    return (-pendulum2.mass2 * pendulum2.length2 * v[6] * cos(v[1] - v[4]) + pendulum2.mass2 * pendulum2.length2 * v[0] * v[3] * sin(v[1] - v[4]) - pendulum2.mass2 * pendulum2.length2 * pow(v[3], 2) * sin(v[1] - v[4]) - pendulum2.mass2 * pendulum2.length2 * v[0] * v[3] * sin(v[1] - v[4]) + pendulum2.mass1 * g * sin(v[1]) + pendulum2.mass2 * g * sin(v[1])) / (pendulum2.mass1 * pendulum2.length1 + pendulum2.mass2 * pendulum2.length1);
}

double fdouble_pendulum_2(double t, std::vector<double>v, complex_pendulum* Pendulum2) {
    //v2, p2, a2, v1, p1, a1
    complex_pendulum pendulum2 = *Pendulum2;
    return (-pendulum2.length1 * v[5] * cos(v[4] - v[1]) + pendulum2.length1 * pow(v[3], 2) * sin(v[4] - v[1]) + g * sin(v[1])) / pendulum2.length2;
}