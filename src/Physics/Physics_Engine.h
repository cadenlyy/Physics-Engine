#pragma once

#include <queue>

#include "Vec2d.h"
#include "Objects.h"

extern void test(Ball& Ball1, double s);
extern void ball_terminal_velocity(Ball& ball1, double s);
extern void thrown_ball(Ball& ball1, double s);
static void single_pendulum_period(ppd& Positions);
static void single_pendulum(ppd& Positions);
static void double_pendulum(ppd& Positions);