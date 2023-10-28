#include <thread>
#include <queue>
#include <iostream>
#include <Windows.h>

#include "Application/Application.h"
#include "Physics/Physics_Engine.h"
#include "Physics/Vec2d.h"
#include "Objects.h"

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
	float color[4] = { 0.2f, 0.3f, 0.8f, 0.1f };
	Ball Ball1(vec2d::CalculateMagnitude(0, 10, 0), vec2d::CalculateMagnitude(15 , 7.5, 0), { {0,0},{0,0} }, 0.2f, 0.3f, 0.8f, 0.1f, 100, 0.7, 100);
	double ts = 0.0001;
	std::thread application(app, &Ball1);
	std::thread physics(Call_Engine<Ball>, std::ref(Ball1), ts, thrown_ball);
	
	std::cout << "Physics Engine Running." << "\n";

	application.join();
	physics.join();
	
	

	
	
}