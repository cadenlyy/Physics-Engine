#include <thread>
#include <queue>
#include <iostream>
#include <Windows.h>

#include "Application/Application.h"
#include "Physics/Physics_Engine.h"
#include "Physics/Objects.h"

template <class T>
extern void Call_Engine(T& object, double ts, void(*f)(T&, double)) {
	LARGE_INTEGER freq;
	LARGE_INTEGER t1, t2;
	double elapsedTime = 0, prevTS = ts;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&t1);

	f(object, ts);

	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart /1000;

	while (1) {
		if (elapsedTime < prevTS) {
			//std::cout << 'a' << ' ' << elapsedTime << '\n';
			Sleep(ts * 1000 - elapsedTime);
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&t1);

			f(object, ts);

			QueryPerformanceCounter(&t2);
			elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart / 1000;
			prevTS = ts;
		}
		else {
			//std::cout << 'b' << ' ' << elapsedTime << '\n';
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&t1);

			f(object, elapsedTime);

			QueryPerformanceCounter(&t2);
			elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart / 1000;
			prevTS = elapsedTime;
		}
	}
}

int main() {
	/*ts and tfr
	thread physics engine and app
	when physics engine finish
		update pos
	when app finish take most recent value in pos
	*/
	
	ball ball1;
	ball1.mass = 100;
	ball1.radius = 0.7;
	ball1.pos.magnitude = vec2d::calculateMagnitude(960/2, 500, 0);;
	ball1.v.magnitude = { {0,0},{0,0} };
	double ts = 0.0001;
	std::thread physics(Call_Engine<ball>, std::ref(ball1), ts, ball_terminal_velocity);
	std::thread application(app, &ball1.pos.magnitude);
	
	std::cout << "Physics Engine Running." << "\n";

	physics.join();
	application.join();
}