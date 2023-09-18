# Physics-Engine
2D physics engine

Equation based Physics simulator

Uses Runge Kutta(RK4) as an ordinary differential equation(ODE) solver

Outputs into a CVS file which can be run through the /graph_creater.py file
  Series of graph and input values need to be changed for different simulations in this file

Contains 4 simulations
  Ball dropping
  Thrown ball
  Simple pendulum
  Double pendulum
  
initial conditions of each simulation has to be changed in the /Object.h file and the simulation being run must be changed under int32_t main in the /Main.cpp file constants can be found and changed in the /constant.h file and vector functions can be found in /Vector_functions.h file

