#pragma once

#include <vector>

#include "Objects.h"

double fball_y(double t, std::vector<double> v, Ball ball1);
double fball_x(double t, std::vector<double> v, Ball ball1);
double fsimple_pendulum(double t, std::vector<double>v, Simple_pendulum Pendulum1);
double fdouble_pendulum_1(double t, std::vector<double>v, Complex_pendulum Pendulum2);
double fdouble_pendulum_2(double t, std::vector<double>v, Complex_pendulum Pendulum2);