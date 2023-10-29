#include<iostream>

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
	pos.push_back(Position.Magnitude.first.first * 100);
	pos.push_back(Position.Magnitude.first.second * 100);
	float BaseAng = 2*PI / Sides;
	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(Position.Magnitude.first.first*100 + Radius * sin(ang));
		pos.push_back(Position.Magnitude.first.second*100 + Radius * cos(ang));
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

Simple_pendulum::Simple_pendulum(ppd AnchorPos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Length, double Angv, double Ang, double Radius, int Sides){
	Simple_pendulum::AnchorPos.Magnitude = AnchorPos;
	Simple_pendulum::Position.Magnitude = vec2d::CalculateMagnitude(Simple_pendulum::AnchorPos.Magnitude.first.first + Length * sin(Ang), Simple_pendulum::AnchorPos.Magnitude.first.second - Length * cos(Ang), 0);
	Simple_pendulum::Velocity.Magnitude = Velo;
	Simple_pendulum::Acceleration.Magnitude = Acc;
	Simple_pendulum::Length = Length;
	Simple_pendulum::Angv = Angv;
	Simple_pendulum::Ang = Ang;
	Simple_pendulum::Radius = Radius;
	Simple_pendulum::Sides = Sides;
	float color[4] = { Color1, Color2, Color3, Color4 };
	for (int i = 0; i < 4; i++) Simple_pendulum::Color[i] = color[i];
	Simple_pendulum::VertexPos = Simple_pendulum::VertexOfSimplePendulum(Radius, Sides);
	Simple_pendulum::IndexPos = Simple_pendulum::IndexOfSimplePendulum(Sides);
}
std::vector<float> Simple_pendulum::VertexOfSimplePendulum(float radius, int Sides) {
	float Radius = radius * 100;
	std::vector <float> pos;
	pos.push_back(AnchorPos.Magnitude.first.first * 100 + 1.0f * cos(PI / 2 + Ang));
	pos.push_back(AnchorPos.Magnitude.first.second * 100 + 1.0f * sin(PI / 2 + Ang));
	pos.push_back(AnchorPos.Magnitude.first.first * 100 + 1.0f * sin(PI / 2 - Ang));
	pos.push_back(AnchorPos.Magnitude.first.second * 100 + 1.0f * cos(PI / 2 - Ang));
	pos.push_back(Position.Magnitude.first.first * 100 - 1.0f * sin(PI / 2 - Ang));
	pos.push_back(Position.Magnitude.first.second * 100 - 1.0f * cos(PI / 2 - Ang));
	pos.push_back(Position.Magnitude.first.first * 100 - 1.0f * cos(PI / 2 + Ang));
	pos.push_back(Position.Magnitude.first.second * 100 - 1.0f * sin(PI / 2 + Ang));
	float BaseAng = 2 * PI / Sides;
	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(Position.Magnitude.first.first * 100 + Radius * sin(ang));
		pos.push_back(Position.Magnitude.first.second * 100 + Radius * cos(ang));

		ang -= BaseAng;
	}
	return pos;
}
std::vector<unsigned int> Simple_pendulum::IndexOfSimplePendulum(int Count) {
	std::vector <unsigned int> ind;
	ind.push_back(0); ind.push_back(1); ind.push_back(2); ind.push_back(0); ind.push_back(2); ind.push_back(3);
	for (int i = 5; i <= Count + 3; i++) {
		if (i != Count+3) {
			ind.push_back(4);
			ind.push_back(i);
			ind.push_back(i + 1);
		}
		else {
			ind.push_back(4);
			ind.push_back(i);
			ind.push_back(5);
		}
	}
	return ind;
}

