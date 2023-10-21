#pragma once

#include<vector>

typedef std::pair<double, double> pd;
typedef std::pair<pd,pd> ppd;

class vec2d{
public:
    ppd magnitude;
    static ppd calculateMagnitude(double x, double y, bool c);
    static ppd add(ppd x, ppd y);
    static ppd multi(ppd x, ppd y);
    static ppd divide(ppd x, ppd y);
    static ppd sum(std::vector <ppd> v);
    static double angle_add(double x, double y);
};