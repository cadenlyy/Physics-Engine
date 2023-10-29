#include <iostream>
#include<math.h>

#include "Physics_Engine.h"
#include "constants.h"
#include "Objects.h"
#include "Force.h"
#include "RK4.cpp"

extern void test(Ball& Ball1, double s) {
	Ball1.Position.Magnitude = vec2d::CalculateMagnitude(960/2,540/2,0);
}

extern void ball_terminal_velocity(Ball& Ball1, double s) {
	double  tc = 0;
	std::vector <double> v;
	tc += s;
	v = { Ball1.Velocity.Magnitude.first.second };
	Ball1.Velocity.Magnitude.first.second = RK4<Ball>(tc, v, s, Ball1, fball_y, 0);
	v = { Ball1.Velocity.Magnitude.first.second, Ball1.Position.Magnitude.first.second };
	Ball1.Position.Magnitude.first.second = RK4<Ball>(tc, v, s, Ball1, fball_y, 1);
	Ball1.VertexPos = Ball1.VertexOfBall(Ball1.Radius, Ball1.Sides);
}

extern void thrown_ball(Ball& Ball1, double s){
	double tc = 0;
	std::vector<double>v;
	tc += s;
	v = {Ball1.Velocity.Magnitude.first.first};
	Ball1.Velocity.Magnitude.first.first = RK4<Ball>(tc, v, s, Ball1, fball_x, 0);
	v = {Ball1.Velocity.Magnitude.first.second};
	Ball1.Velocity.Magnitude.first.second = RK4<Ball>(tc, v, s, Ball1, fball_y, 0);
	v = {Ball1.Velocity.Magnitude.first.first, Ball1.Position.Magnitude.first.first};
	Ball1.Position.Magnitude.first.first = RK4<Ball>(tc, v, s, Ball1, fball_x, 1);
	v = {Ball1.Velocity.Magnitude.first.second, Ball1.Position.Magnitude.first.second};
	Ball1.Position.Magnitude.first.second = RK4<Ball>(tc, v, s, Ball1, fball_y, 1);
	Ball1.VertexPos = Ball1.VertexOfBall(Ball1.Radius, Ball1.Sides);
}

static void single_pendulum_period(Simple_pendulum pendulum1 ,ppd& Positions){
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	double counter =  0.1, countstep = 0.1;
	while(counter < PI/2){
		double s = 0.0001, tc = 0;
		std::vector<double>v;
		pendulum1.Ang = counter;
		pendulum1.Position.Magnitude = pendulum1.Position.CalculateMagnitude(pendulum1.Length,PI-pendulum1.Ang,1);
		double c = pendulum1.Position.Magnitude.first.first;
		c -= 0.001;
		while(c > pendulum1.Position.Magnitude.first.first or tc < 1){//end condition
			tc += s;
			v = {pendulum1.Angv, pendulum1.Ang};
			pendulum1.Angv = RK4<Simple_pendulum>(tc, v, s, pendulum1, fsimple_pendulum, 0);
			v = {pendulum1.Angv, pendulum1.Ang};
			pendulum1.Ang = RK4<Simple_pendulum>(tc, v, s, pendulum1, fsimple_pendulum, 1);
			pendulum1.Position.Magnitude = pendulum1.Position.CalculateMagnitude(pendulum1.Length,PI-pendulum1.Ang,1);
			//fout << tc << ',' << pendulum1.angv << ',' << pendulum1.ang << ',' << pendulum1.pos.first.first << ',' << pendulum1.pos.first.second << "\n"; //output graph axis
		}
		//fout << counter << ',' << tc << "\n";
		counter += countstep;
	}
}

extern void single_pendulum(Simple_pendulum& Pendulum1, double s){
	double tc = 0;
	std::vector<double>v;
	tc += s;
	v = {Pendulum1.Angv, Pendulum1.Ang};
	Pendulum1.Angv = RK4<Simple_pendulum>(tc, v, s, Pendulum1, fsimple_pendulum, 0);
	v = {Pendulum1.Angv, Pendulum1.Ang};
	Pendulum1.Ang = RK4<Simple_pendulum>(tc, v, s, Pendulum1, fsimple_pendulum, 1);
	Pendulum1.Position.Magnitude = vec2d::CalculateMagnitude(Pendulum1.AnchorPos.Magnitude.first.first + Pendulum1.Length * sin(Pendulum1.Ang), Pendulum1.AnchorPos.Magnitude.first.second - Pendulum1.Length * cos(Pendulum1.Ang), 0);
	Pendulum1.VertexPos = Pendulum1.VertexOfSimplePendulum(Pendulum1.Radius, Pendulum1.Sides);
}

extern void double_pendulum(Complex_pendulum& Pendulum2, double s){
	double tc = 0;
	std::vector<double>v;
	tc += s;
	v = {Pendulum2.Angv, Pendulum2.Ang, Pendulum2.Anga, Pendulum2.Angv2, Pendulum2.Ang2, Pendulum2.Anga2};
	Pendulum2.Anga = fdouble_pendulum_1(tc,v,Pendulum2);
	v = {Pendulum2.Angv2, Pendulum2.Ang2, Pendulum2.Anga2, Pendulum2.Angv, Pendulum2.Ang, Pendulum2.Anga};
	Pendulum2.Anga2 = fdouble_pendulum_2(tc,v, Pendulum2);
	v = {Pendulum2.Angv, Pendulum2.Ang, Pendulum2.Anga, Pendulum2.Angv2, Pendulum2.Ang2, Pendulum2.Anga2};
	Pendulum2.Angv = RK4<Complex_pendulum>(tc, v, s, Pendulum2, fdouble_pendulum_1, 0);
	v = {Pendulum2.Angv2, Pendulum2.Ang2, Pendulum2.Anga2, Pendulum2.Angv, Pendulum2.Ang, Pendulum2.Anga};
	Pendulum2.Angv2 = RK4<Complex_pendulum>(tc, v, s, Pendulum2, fdouble_pendulum_2, 0);
	v = {Pendulum2.Angv, Pendulum2.Ang, Pendulum2.Anga, Pendulum2.Angv2, Pendulum2.Ang2, Pendulum2.Anga2};
	Pendulum2.Ang = RK4<Complex_pendulum>(tc, v, s, Pendulum2, fdouble_pendulum_1, 1);
	v = {Pendulum2.Angv2, Pendulum2.Ang2, Pendulum2.Anga2, Pendulum2.Angv, Pendulum2.Ang, Pendulum2.Anga};
	Pendulum2.Ang2 = RK4<Complex_pendulum>(tc, v, s, Pendulum2, fdouble_pendulum_2, 1);
	Pendulum2.Position.Magnitude = vec2d::CalculateMagnitude(Pendulum2.AnchorPos.Magnitude.first.first + Pendulum2.Length * sin(Pendulum2.Ang), Pendulum2.AnchorPos.Magnitude.first.second - Pendulum2.Length * cos(Pendulum2.Ang), 0);
	Pendulum2.Position2.Magnitude = vec2d::CalculateMagnitude(Pendulum2.Position.Magnitude.first.first + Pendulum2.Length2 * sin(Pendulum2.Ang2), Pendulum2.Position.Magnitude.first.second - Pendulum2.Length2 * cos(Pendulum2.Ang2), 0);
	Pendulum2.VertexPos = Pendulum2.VertexOfComplexPendulum(Pendulum2.Radius, Pendulum2.Radius2, Pendulum2.Sides);
}

