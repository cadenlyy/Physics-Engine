#include <thread>
#include <queue>
#include <iostream>
#include <Windows.h>
#include <string>

#include "Application/Application.h"
#include "Physics/Physics_Engine.h"
#include "Physics/Vec2d.h"
#include "Objects.h"
#include "Physics/GJK.h"
#include "Physics/Minkowski_Difference.h"
#include "Physics/Support.h"
#include "Physics/Normal.h"
#include "s_vector.h"

template <class T>
extern void Call_Engine(T& object, double ts, void(*f)(T&, double, std::string), std::string ODES) {
	if (ODES != "RK4" and ODES != "Euler") std::cout << "ODES invalid Type" << std::endl;

	LARGE_INTEGER freq;
	LARGE_INTEGER t1, t2;
	double elapsedTime = 0, prevTS = ts;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&t1);

	f(object, ts, ODES);

	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart /1000;

	while (1) {
		if (elapsedTime < prevTS) {
			Sleep(ts * 1000 - elapsedTime);
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&t1);

			f(object, ts, ODES);

			QueryPerformanceCounter(&t2);
			elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart / 1000;
			prevTS = ts;
		}
		else {
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&t1);

			f(object, elapsedTime, ODES);

			QueryPerformanceCounter(&t2);
			elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart / 1000;
			prevTS = elapsedTime;
		}
	}
}

int main() {
	/*Position, Velo, Acceleration, Colour1, Colour2, Colour3, Colour4, Mass, Radius, Sides*/
	Ball Ball1(vec2d::CalculateMagnitude(10, 10, 0), vec2d::CalculateMagnitude(15 , 7.5, 0), { {0,0},{0,0} }, 0.2f, 0.3f, 0.8f, 0.1f, 100, 0.7, 100);
	/*Anchorpos, Velo, Acc, Colour1, Colour2, Colour3, Colour4, Length, Angv, Ang, Radius, Sides*/
	Simple_pendulum Pendulum1(vec2d::CalculateMagnitude(18, 21, 0), vec2d::CalculateMagnitude(0, 0, 0), { {0,0},{0,0} }, 0.2f, 0.3f, 0.8f, 0.1f, 10, 0, PI/5, 0.7, 30);
	/*                         Anchorpos,                            Velo,                               Acc,                                Colour1, Colour2, Colour3, Colour4, Mass, Length, Anga, Angv, Ang, Radius, Velo2,                              Acc2,                               Mass2, Length2, Anga2, Angv2, Ang2, Radius2, Sides*/
	Complex_pendulum Pendulum2(vec2d::CalculateMagnitude(18, 11, 0), vec2d::CalculateMagnitude(0, 0, 0), vec2d::CalculateMagnitude(0, 0, 0), 0.2f, 0.3f, 0.8f, 0.1f, 10, 5, 0, 0.01, PI, 0.3, vec2d::CalculateMagnitude(0, 0, 0), vec2d::CalculateMagnitude(0, 0, 0), 20, 3, 0, 0, PI / 2, 1, 100);
	double ts = 0.001;
	std::thread application(app, &Pendulum2);
	/*Class type, object, timestep, simulation function, ODES type*/
	std::thread physics(Call_Engine<Complex_pendulum>, std::ref(Pendulum2), ts, double_pendulum, "RK4");
	
	std::cout << "Physics Engine Running." << "\n";

	application.join();
	physics.join();

	system("pause");
}