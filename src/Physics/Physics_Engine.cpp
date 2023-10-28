#include <iostream>
#include<math.h>

#include "Physics_Engine.h"
#include "constants.h"
#include "Objects.h"
#include "Force.h"
#include "RK4.cpp"

extern void test(Ball& Ball1, double s) {
	Ball1.Position.Magnitude = vec2d::CalculateMagnitude(960/2,540/2,0);
	std::cout << Ball1.Velocity.Magnitude.first.first << ' ' << Ball1.Velocity.Magnitude.first.second << ' ' << Ball1.Position.Magnitude.first.first << ' ' << Ball1.Position.Magnitude.first.second << '\n';
}

extern void ball_terminal_velocity(Ball& Ball1, double s) {
	double  tc = 0;
	std::vector <double> v;
	tc += s;
	v = { Ball1.Velocity.Magnitude.first.second };
	Ball1.Velocity.Magnitude.first.second = RK4<Ball>(tc, v, s, Ball1, fball_y, 0);
	v = { Ball1.Velocity.Magnitude.first.second, Ball1.Position.Magnitude.first.second };
	Ball1.Position.Magnitude.first.second = RK4<Ball>(tc, v, s, Ball1, fball_y, 1);
	std::cout << Ball1.Velocity.Magnitude.first.first << ' ' << Ball1.Velocity.Magnitude.first.second << ' ' << Ball1.Position.Magnitude.first.first << ' ' << Ball1.Position.Magnitude.first.second << '\n';
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
}

static void single_pendulum_period(ppd& Positions){
	simple_pendulum pendulum1;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	double counter =  0.1, countstep = 0.1;
	while(counter < PI/2){
		double s = 0.0001, tc = 0;
		std::vector<double>v;
		pendulum1.ang = counter;
		pendulum1.pos.Magnitude = pendulum1.pos.CalculateMagnitude(pendulum1.length,PI-pendulum1.ang,1);
		double c = pendulum1.pos.Magnitude.first.first;
		c -= 0.001;
		while(c > pendulum1.pos.Magnitude.first.first or tc < 1){//end condition
			tc += s;
			v = {pendulum1.angv, pendulum1.ang};
			pendulum1.angv = RK4<simple_pendulum>(tc, v, s, pendulum1, fsimple_pendulum, 0);
			v = {pendulum1.angv, pendulum1.ang};
			pendulum1.ang = RK4<simple_pendulum>(tc, v, s, pendulum1, fsimple_pendulum, 1);
			pendulum1.pos.Magnitude = pendulum1.pos.CalculateMagnitude(pendulum1.length,PI-pendulum1.ang,1);
			//fout << tc << ',' << pendulum1.angv << ',' << pendulum1.ang << ',' << pendulum1.pos.first.first << ',' << pendulum1.pos.first.second << "\n"; //output graph axis
		}
		//fout << counter << ',' << tc << "\n";
		counter += countstep;
	}
}

static void single_pendulum(ppd& Positions){
	simple_pendulum pendulum1;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	double s = 0.0001, tc = 0;
	std::vector<double>v;
	while(tc < 10){//end condition
		tc += s;
		v = {pendulum1.angv, pendulum1.ang};
		pendulum1.angv = RK4<simple_pendulum>(tc, v, s, pendulum1, fsimple_pendulum, 0);
		v = {pendulum1.angv, pendulum1.ang};
		pendulum1.ang = RK4<simple_pendulum>(tc, v, s, pendulum1, fsimple_pendulum, 1);
		pendulum1.pos.Magnitude = pendulum1.pos.CalculateMagnitude(pendulum1.length,PI-pendulum1.ang,1);
		//fout << tc << ',' << pendulum1.angv << ',' << pendulum1.ang << ',' << pendulum1.pos.Magnitude.first.first << ',' << pendulum1.pos.Magnitude.first.second << "\n"; //output graph axis
	}
}

static void double_pendulum(ppd& Positions){
	complex_pendulum pendulum2;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	double s = 0.0001, tc = 0;
	std::vector<double>v;
	while(tc <= 100){//end condition
		tc += s;
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.anga1 = fdouble_pendulum_1(tc,v,pendulum2);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.anga2 = fdouble_pendulum_2(tc,v, pendulum2);
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.angv1 = RK4<complex_pendulum>(tc, v, s, pendulum2, fdouble_pendulum_1, 0);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.angv2 = RK4<complex_pendulum>(tc, v, s, pendulum2, fdouble_pendulum_2, 0);
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.ang1 = RK4<complex_pendulum>(tc, v, s, pendulum2, fdouble_pendulum_1, 1);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.ang2 = RK4<complex_pendulum>(tc, v, s, pendulum2, fdouble_pendulum_2, 1);
		pendulum2.pos1.Magnitude = pendulum2.pos1.CalculateMagnitude(pendulum2.length1,PI-pendulum2.ang1,1);
		pendulum2.pos2.Magnitude = pendulum2.pos2.CalculateMagnitude(pendulum2.pos1.Magnitude.first.first+pendulum2.length2*sin(pendulum2.ang2),pendulum2.pos1.Magnitude.first.second-pendulum2.length2*cos(pendulum2.ang2),0);
		//fout << tc << ',' << pendulum2.angv1 << ','  << pendulum2.angv2 << ',' << pendulum2.ang1 << ',' << pendulum2.ang2 << ',' << pendulum2.pos1.Magnitude.first.first << ',' << pendulum2.pos1.Magnitude.first.second << ',' << pendulum2.pos2.Magnitude.first.first << ',' << pendulum2.pos2.Magnitude.first.second << "\n"; //output graph axis
    }
}

