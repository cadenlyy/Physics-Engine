#include<vector>
#include<cmath>
#include<iostream>

#include "Shapes.h"

double PI = 3.14159265358979323846;

std::vector<float> Shape::vertexOfCircle(float radius, int Sides){
	std::vector <float> pos;
	pos.push_back(0.0f);
	pos.push_back(0.0f);
	float BaseAng = PI - ((Sides - 2) * PI) / Sides;
	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(radius * sin(ang));
		pos.push_back(radius * cos(ang));
		ang -= BaseAng;
	}
	return pos;
}

std::vector<int> Shape::indexOfCircle(int Count){
	std::vector <int> ind;
	for (int i = 1; i <= Count; i++) {
		if (i != Count) {
			ind.push_back(0);
			ind.push_back(i);
			ind.push_back(i+1);
		}
		else {
			ind.push_back(0);
			ind.push_back(i);
			ind.push_back(1);
		}
	}
	return ind;
}
