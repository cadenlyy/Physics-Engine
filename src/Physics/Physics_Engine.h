#pragma once

#include <queue>

#include "Vec2d.h"
#include "Objects.h"

extern void ball_terminal_velocity(ball& ball1, double s, ppd& Positions);
extern void thrown_ball(ppd& Positions);
static void single_pendulum_period(ppd& Positions);
static void single_pendulum(ppd& Positions);
static void double_pendulum(ppd& Positions);