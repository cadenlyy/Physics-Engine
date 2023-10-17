#include <vector>

#include "Vec2d.h"

extern double RK4(double x, std::vector<double> v, double s, ball ball1, double (*f)(double, std::vector<double>, ball&), int rc) {
	std::vector <double> vk1, vk2, vk3;
	double k1, k2, k3, k4, a;

	if (rc > 0) k1 = RK4(x, v, s, ball1, f, rc - 1);
	else k1 = f(x, v, ball1);

	for (auto i : v) vk1.push_back(i + s * k1 * 0.5);
	if (rc > 0) k2 = RK4(x + 0.5 * s, vk1, s, ball1, f, rc - 1);
	else k2 = f(x + 0.5 * s, v, ball1);

	for (auto i : v) vk2.push_back(i + s * k2 * 0.5);
	if (rc > 0) k3 = RK4(x + 0.5 * s, vk2, s, ball1, f, rc - 1);
	else k3 = f(x + 0.5 * s, vk2, ball1);

	for (auto i : v) vk3.push_back(i + s * k3);
	if (rc > 0) k4 = RK4(x + s, vk3, s, ball1, f, rc - 1);
	else k4 = f(x + s, vk3, ball1);

	if (rc > 0) a = v[1] + s / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
	else a = v[0] + s / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

	return a;
}