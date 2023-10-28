#include<vector>

#include "Vec2d.h"
#include "constants.h"

ppd vec2d::CalculateMagnitude(double x, double y, bool c){
    if (c == false) {
        if (x == 0 and y == 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),0} };
        }
        if (x == 0 and y >= 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),0} };
        }
        if (x >= 0 and y == 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),PI / 2} };
        }
        if (x == 0 and y <= 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),PI} };
        }
        if (x <= 0 and y == 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),PI * 3 / 2} };
        }
        if (x > 0 and y > 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),atan(x / y)} };
        }
        if (x > 0 and y < 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),PI / 2 - atan(x / y)} };
        }
        if (x < 0 and y < 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),PI + atan(x / y)} };
        }
        if (x < 0 and y > 0) {
            return { {x,y},{sqrt(pow(abs(x),2) + pow(abs(y),2)),PI * 2 - atan(x / y)} };
        }
    }
    return { {x * sin(y),x * cos(y)},{x,y} };
}

ppd vec2d::Add(ppd x, ppd y) {
    return CalculateMagnitude(x.first.first + y.first.first, x.first.second + y.first.second, 0);
}

ppd vec2d::Multi(ppd x, ppd y) {
    return CalculateMagnitude(x.first.first * y.first.first, x.first.second * y.first.second, 0);
}

ppd vec2d::Divide(ppd x, ppd y) {
    return CalculateMagnitude(x.first.first / y.first.first, x.first.second / y.first.second, 0);
}

ppd vec2d::Sum(std::vector <ppd> v) {
    ppd ans = CalculateMagnitude(0, 0, 0);
    for (auto i : v) {
        ans = vec2d::Add(ans, i);
    }
    return ans;
}

double vec2d::AngleAdd(double x, double y) {
    if (x + y >= 2 * PI) {
        return x + y - 2 * PI;
    }
    return x + y;
}