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

Complex_pendulum::Complex_pendulum(ppd AnchorPos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Mass, double Length, double Anga, double Angv, double Ang, double Radius, ppd Velo2, ppd Acc2, double Mass2, double Length2, double Anga2, double Angv2, double Ang2, double Radius2, int Sides) {
	Complex_pendulum::AnchorPos.Magnitude = AnchorPos;
	float color[4] = { Color1, Color2, Color3, Color4 };
	for (int i = 0; i < 4; i++) Complex_pendulum::Color[i] = color[i];

	Complex_pendulum::Position.Magnitude = vec2d::CalculateMagnitude(Complex_pendulum::AnchorPos.Magnitude.first.first + Length * sin(Ang), Complex_pendulum::AnchorPos.Magnitude.first.second - Length * cos(Ang), 0);
	Complex_pendulum::Velocity.Magnitude = Velo;
	Complex_pendulum::Acceleration.Magnitude = Acc;
	Complex_pendulum::Mass = Mass;
	Complex_pendulum::Length = Length;
	Complex_pendulum::Anga = Anga;
	Complex_pendulum::Angv = Angv;
	Complex_pendulum::Ang = Ang;
	Complex_pendulum::Radius = Radius;

	Complex_pendulum::Position2.Magnitude = vec2d::CalculateMagnitude(Complex_pendulum::Position.Magnitude.first.first + Length2 * sin(Ang2), Complex_pendulum::Position.Magnitude.first.second - Length2 * cos(Ang2), 0);
	Complex_pendulum::Velocity2.Magnitude = Velo2;
	Complex_pendulum::Acceleration2.Magnitude = Acc2;
	Complex_pendulum::Mass2 = Mass2;
	Complex_pendulum::Length2 = Length2;
	Complex_pendulum::Anga2 = Anga2;
	Complex_pendulum::Angv2 = Angv2;
	Complex_pendulum::Ang2 = Ang2;
	Complex_pendulum::Radius2 = Radius2;

	Complex_pendulum::Sides = Sides;
	
	Complex_pendulum::VertexPos = Complex_pendulum::VertexOfComplexPendulum(Radius, Radius2, Sides);
	Complex_pendulum::IndexPos = Complex_pendulum::IndexOfComplexPendulum(Sides);
}

std::vector<float> Complex_pendulum::VertexOfComplexPendulum(float radius, float radius2, int Sides) {
	float Radius = radius * 100;
	float Radius2 = radius2 * 100;
	float BaseAng = 2 * PI / Sides;
	std::vector <float> pos;

	pos.push_back(AnchorPos.Magnitude.first.first * 100 + 1.0f * cos(PI / 2 + Ang));
	pos.push_back(AnchorPos.Magnitude.first.second * 100 + 1.0f * sin(PI / 2 + Ang));
	pos.push_back(AnchorPos.Magnitude.first.first * 100 + 1.0f * sin(PI / 2 - Ang));
	pos.push_back(AnchorPos.Magnitude.first.second * 100 + 1.0f * cos(PI / 2 - Ang));
	pos.push_back(Position.Magnitude.first.first * 100 - 1.0f * sin(PI / 2 - Ang));
	pos.push_back(Position.Magnitude.first.second * 100 - 1.0f * cos(PI / 2 - Ang));
	pos.push_back(Position.Magnitude.first.first * 100 - 1.0f * cos(PI / 2 + Ang));
	pos.push_back(Position.Magnitude.first.second * 100 - 1.0f * sin(PI / 2 + Ang));

	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(Position.Magnitude.first.first * 100 + Radius * sin(ang));
		pos.push_back(Position.Magnitude.first.second * 100 + Radius * cos(ang));
		ang -= BaseAng;
	}

	pos.push_back(Position.Magnitude.first.first * 100 + 1.0f * cos(PI / 2 + Ang));
	pos.push_back(Position.Magnitude.first.second * 100 + 1.0f * sin(PI / 2 + Ang));
	pos.push_back(Position.Magnitude.first.first * 100 + 1.0f * sin(PI / 2 - Ang));
	pos.push_back(Position.Magnitude.first.second * 100 + 1.0f * cos(PI / 2 - Ang));
	pos.push_back(Position2.Magnitude.first.first * 100 - 1.0f * sin(PI / 2 - Ang));
	pos.push_back(Position2.Magnitude.first.second * 100 - 1.0f * cos(PI / 2 - Ang));
	pos.push_back(Position2.Magnitude.first.first * 100 - 1.0f * cos(PI / 2 + Ang));
	pos.push_back(Position2.Magnitude.first.second * 100 - 1.0f * sin(PI / 2 + Ang));

	ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(Position2.Magnitude.first.first * 100 + Radius2 * sin(ang));
		pos.push_back(Position2.Magnitude.first.second * 100 + Radius2 * cos(ang));
		ang -= BaseAng;
	}

	return pos;
}

std::vector<unsigned int> Complex_pendulum::IndexOfComplexPendulum(int Count) {
	std::vector <unsigned int> ind;
	ind.push_back(0); ind.push_back(1); ind.push_back(2); ind.push_back(0); ind.push_back(2); ind.push_back(3);
	for (int i = 5; i <= Count + 3; i++) {
		if (i != Count + 3) {
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
	ind.push_back(Count+4); ind.push_back(Count + 5); ind.push_back(Count + 6); ind.push_back(Count + 4); ind.push_back(Count + 6); ind.push_back(Count + 7);
	for (int i = Count + 9; i <= Count + 4 + Count + 3; i++) {
		if (i != Count + 4 + Count + 3) {
			ind.push_back(Count + 8);
			ind.push_back(i);
			ind.push_back(i + 1);
		}
		else {
			ind.push_back(Count + 8);
			ind.push_back(i);
			ind.push_back(Count + 9);
		}
	}
	return ind;
}