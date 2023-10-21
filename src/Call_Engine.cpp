#include<iostream>
#include<Windows.h>

#include "Physics/Vec2d.h"
#include "Physics/Objects.h"

template <class T>
extern void Call_Engine(T& object, double ts, ppd& pos, void(*f)(T&, double, ppd&)) {
	LARGE_INTEGER freq;
	LARGE_INTEGER t1, t2;
	double elapsedTime = 0, prevTS = ts;

	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&t1);

	f(object, ts, pos);

	QueryPerformanceCounter(&t2);
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart;

	while (1) {
		if (elapsedTime < prevTS) {
			Sleep(ts * 1000 - elapsedTime);
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&t1);

			f(object, ts, pos);

			QueryPerformanceCounter(&t2);
			elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart;
			prevTS = ts;
		}
		else {
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&t1);

			f(object, ts + (elapsedTime - ts * 1000), pos);

			QueryPerformanceCounter(&t2);
			elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart;
			prevTS = ts + (elapsedTime - ts * 1000);
		}
	}
}