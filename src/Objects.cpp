#include "Objects.h"

Ball::Ball(ppd Pos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Mass, double Radius, int Sides){
	Ball::Position.Magnitude = Pos;
	Ball::Velocity.Magnitude = Velo;
	Ball::Acceleration.Magnitude = Acc;
	Ball::Mass = Mass;
	Ball::Radius = Radius;
	Ball::Sides = Sides;
	float color[4] = {Color1, Color2, Color3, Color4};
	for(int i = 0; i < 4; i++) Ball::Color[i] = color[i];
	Ball::VertexPos = Ball::VertexOfBall(Radius, Sides);
	Ball::IndexPos = Ball::IndexOfBall(Sides);
}

std::vector<float> Ball::VertexOfBall(float radius, int Sides) {
	float Radius = radius * 100;
	std::vector <float> pos;
	pos.push_back(0.0f);
	pos.push_back(0.0f);
	float BaseAng = PI - ((Sides - 2) * PI) / Sides;
	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(Radius * sin(ang));
		pos.push_back(Radius * cos(ang));
		ang -= BaseAng;
	}
	return pos;
}

std::vector<unsigned int> Ball::IndexOfBall(int Count) {
	std::vector <unsigned int> ind;
	for (int i = 1; i <= Count; i++) {
		if (i != Count) {
			ind.push_back(0);
			ind.push_back(i);
			ind.push_back(i + 1);
		}
		else {
			ind.push_back(0);
			ind.push_back(i);
			ind.push_back(1);
		}
	}
	return ind;
}