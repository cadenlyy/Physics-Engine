#include <iostream>
#include<math.h>
#include<queue>
//#include <filesystem>
//#include <fstream>

#include "constants.h"
#include "Objects.h"
#include "Force.h"
#include "RK4.cpp"

static void ball_terminal_velocity (std::queue <ppd>& Positions){
	ball ball1;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\src\\graph.csv", std::ios::trunc);
	ball1.v.magnitude = ball1.v.calculateMagnitude(10,0,0);
    ball1.pos.magnitude = ball1.v.calculateMagnitude(0,0,0);
    ball1.mass = 2;
    ball1.radius = 0.7;
	double s = 0.01, tc = 0;
	std::vector <double> v = {ball1.v.magnitude.first.second};
	while(tc < 10){//end condition
		tc += s;
		v = {ball1.v.magnitude.first.second};
		ball1.v.magnitude.first.second = RK4(tc, v, s, fball_y, 0);
		v = { ball1.v.magnitude.first.first, ball1.pos.magnitude.first.first};
		ball1.pos.magnitude.first.first = vec2d::calculateMagnitude(RK4(tc, v, s, fball_x, 1), ball1.pos.magnitude.first.second,0).first.first;
		v = { ball1.v.magnitude.first.second, ball1.pos.magnitude.first.second };
		ball1.pos.magnitude.first.second = vec2d::calculateMagnitude(ball1.pos.magnitude.first.first, RK4(tc, v, s, fball_y, 1), 0).first.first;
		//ball1.pos = compound_rk4(tc, ball1.v, ball1.pos, s, fball);
		//fout << tc << ',' << ball1.v.magnitude.first.first << ',' << ball1.v.magnitude.first.second << "\n"; //output graph axis
		std::cout << ball1.pos.magnitude.first.first << ' ' << ball1.pos.magnitude.first.second;
		Positions.push(ball1.pos.magnitude);
	}
}

static void thrown_ball(std::queue <ppd>& Positions){
	ball ball1;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	ball1.v.magnitude = ball1.v.calculateMagnitude(10,0,0);
    ball1.pos.magnitude = ball1.v.calculateMagnitude(0,0,0);
    ball1.mass = 2;
    ball1.radius = 0.7;
	double s = 0.0001, tc = 0;
	std::vector<double>v;
	while(tc <= 10){//end condition
		tc += s;
		v = {ball1.v.magnitude.first.first};
		ball1.v.magnitude.first.first = RK4(tc, v, s, fball_x, 0);
		v = {ball1.v.magnitude.first.second};
		ball1.v.magnitude.first.second = RK4(tc, v, s, fball_y, 0);
		v = {ball1.v.magnitude.first.first, ball1.pos.magnitude.first.first};
		ball1.pos.magnitude.first.first = RK4(tc, v, s, fball_x, 1);
		v = {ball1.v.magnitude.first.second, ball1.pos.magnitude.first.second};
		ball1.pos.magnitude.first.second = RK4(tc, v, s, fball_y, 1);
		//fout << tc << ',' << ball1.v.magnitude.first.first << ',' << ball1.v.magnitude.first.second << ',' << ball1.pos.magnitude.first.first << ',' << ball1.pos.magnitude.first.second << "\n"; //output graph axis
    }
}

static void single_pendulum_period(std::queue <ppd>& Positions){
	simple_pendulum pendulum1;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	double counter =  0.1, countstep = 0.1;
	while(counter < PI/2){
		double s = 0.0001, tc = 0;
		std::vector<double>v;
		pendulum1.ang = counter;
		pendulum1.pos.magnitude = pendulum1.pos.calculateMagnitude(pendulum1.length,PI-pendulum1.ang,1);
		double c = pendulum1.pos.magnitude.first.first;
		c -= 0.001;
		while(c > pendulum1.pos.magnitude.first.first or tc < 1){//end condition
			tc += s;
			v = {pendulum1.angv, pendulum1.ang};
			pendulum1.angv = RK4(tc, v, s, fsimple_pendulum, 0);
			v = {pendulum1.angv, pendulum1.ang};
			pendulum1.ang = RK4(tc, v, s, fsimple_pendulum, 1);
			pendulum1.pos.magnitude = pendulum1.pos.calculateMagnitude(pendulum1.length,PI-pendulum1.ang,1);
			//fout << tc << ',' << pendulum1.angv << ',' << pendulum1.ang << ',' << pendulum1.pos.first.first << ',' << pendulum1.pos.first.second << "\n"; //output graph axis
		}
		//fout << counter << ',' << tc << "\n";
		counter += countstep;
	}
}

static void single_pendulum(std::queue <ppd>& Positions){
	simple_pendulum pendulum1;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	double s = 0.0001, tc = 0;
	std::vector<double>v;
	while(tc < 10){//end condition
		tc += s;
		v = {pendulum1.angv, pendulum1.ang};
		pendulum1.angv = RK4(tc, v, s, fsimple_pendulum, 0);
		v = {pendulum1.angv, pendulum1.ang};
		pendulum1.ang = RK4(tc, v, s, fsimple_pendulum, 1);
		pendulum1.pos.magnitude = pendulum1.pos.calculateMagnitude(pendulum1.length,PI-pendulum1.ang,1);
		//fout << tc << ',' << pendulum1.angv << ',' << pendulum1.ang << ',' << pendulum1.pos.magnitude.first.first << ',' << pendulum1.pos.magnitude.first.second << "\n"; //output graph axis
	}
}

static void double_pendulum(std::queue <ppd>& Positions){
	complex_pendulum pendulum2;
	//std::ofstream fout;
    //fout.open("C:\\Users\\caden\\Documents\\code\\C++\\self\\Physics Engine\\graph.csv", std::ios::trunc);
	double s = 0.0001, tc = 0;
	std::vector<double>v;
	while(tc <= 100){//end condition
		tc += s;
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.anga1 = fdouble_pendulum_1(tc,v);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.anga2 = fdouble_pendulum_2(tc,v);
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.angv1 = RK4(tc, v, s, fdouble_pendulum_1, 0);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.angv2 = RK4(tc, v, s, fdouble_pendulum_2, 0);
		v = {pendulum2.angv1, pendulum2.ang1, pendulum2.anga1, pendulum2.angv2, pendulum2.ang2, pendulum2.anga2};
		pendulum2.ang1 = RK4(tc, v, s, fdouble_pendulum_1, 1);
		v = {pendulum2.angv2, pendulum2.ang2, pendulum2.anga2, pendulum2.angv1, pendulum2.ang1, pendulum2.anga1};
		pendulum2.ang2 = RK4(tc, v, s, fdouble_pendulum_2, 1);
		pendulum2.pos1.magnitude = pendulum2.pos1.calculateMagnitude(pendulum2.length1,PI-pendulum2.ang1,1);
		pendulum2.pos2.magnitude = pendulum2.pos2.calculateMagnitude(pendulum2.pos1.magnitude.first.first+pendulum2.length2*sin(pendulum2.ang2),pendulum2.pos1.magnitude.first.second-pendulum2.length2*cos(pendulum2.ang2),0);
		//fout << tc << ',' << pendulum2.angv1 << ','  << pendulum2.angv2 << ',' << pendulum2.ang1 << ',' << pendulum2.ang2 << ',' << pendulum2.pos1.magnitude.first.first << ',' << pendulum2.pos1.magnitude.first.second << ',' << pendulum2.pos2.magnitude.first.first << ',' << pendulum2.pos2.magnitude.first.second << "\n"; //output graph axis
    }
}

