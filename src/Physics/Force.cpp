#include <vector>

#include "Force.h"
#include "constants.h"
#include "Objects.h"

extern double fball_y(double t, std::vector<double> v, Ball ball1) {
    double weight = ball1.Mass * g;
    double air_resistance = (p * (2 * PI * ball1.Radius * ball1.Radius) * c * v[0] * v[0]) / 2;
    double bouyancy = -(p * g * ((4 / 3) * PI * ball1.Radius * ball1.Radius * ball1.Radius));
    double force = weight + air_resistance + bouyancy;
    return force / ball1.Mass;
}

extern double  fball_x(double t, std::vector<double> v, Ball ball1) {
    double air_resistance = -(p * (2 * PI * ball1.Radius * ball1.Radius) * c * v[0] * v[0]) / 2;
    return air_resistance / ball1.Mass;
}

extern double  fsimple_pendulum(double t, std::vector<double>v, Simple_pendulum Pendulum1) {
    return (g * sin(v[1])) / Pendulum1.Length;
}

extern double fdouble_pendulum_1(double t, std::vector<double>v, Complex_pendulum Pendulum2) {
    // v1, p1, a1, v2, p2, a2
    return (-Pendulum2.Mass2 * Pendulum2.Length2 * v[6] * cos(v[1] - v[4]) + Pendulum2.Mass2 * Pendulum2.Length2 * v[0] * v[3] * sin(v[1] - v[4]) - Pendulum2.Mass2 * Pendulum2.Length2 * pow(v[3], 2) * sin(v[1] - v[4]) - Pendulum2.Mass2 * Pendulum2.Length2 * v[0] * v[3] * sin(v[1] - v[4]) + Pendulum2.Mass * g * sin(v[1]) + Pendulum2.Mass2 * g * sin(v[1])) / (Pendulum2.Mass * Pendulum2.Length + Pendulum2.Mass2 * Pendulum2.Length);
}

extern double fdouble_pendulum_2(double t, std::vector<double>v, Complex_pendulum Pendulum2) {
    //v2, p2, a2, v1, p1, a1
    return (-Pendulum2.Length * v[5] * cos(v[4] - v[1]) + Pendulum2.Length * pow(v[3], 2) * sin(v[4] - v[1]) + g * sin(v[1])) / Pendulum2.Length2;
}