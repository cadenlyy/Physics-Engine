#include <thread>
#include <queue>
#include <iostream>

#include "Application/Application.h"
#include "Physics/Physics_Engine.h"
#include "Call_Engine.cpp"
#include "Physics/Objects.h"



int main() {
	/*ts and tfr
	thread physics engine and app
	when physics engine finish
		update pos
	when app finish take most recent value in pos
	*/
	ppd Pos = { {0,0},{0,0} };
	ball ball1;
	double ts = 0.01;
	std::thread physics(Call_Engine<ball>, std::ref(ball1), ts, std::ref(Pos), ball_terminal_velocity);
	std::thread application(app, std::ref(Pos));
	
	std::cout << "Physics Engine Running.";

	physics.join();
	application.join();
}