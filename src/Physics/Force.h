#pragma once

#include <vector>

double fball_y(double t, std::vector<double> v, ball* ball1);
double fball_x(double t, std::vector<double> v, ball* ball1);
double fsimple_pendulum(double t, std::vector<double>v, simple_pendulum* pendulum1);
double fdouble_pendulum_1(double t, std::vector<double>v, complex_pendulum* pendulum2);
double fdouble_pendulum_2(double t, std::vector<double>v, complex_pendulum* pendulum2);