#include<vector>

#include "Vec2d.h"
#include "constants.h"

ppd vec2d::calculateMagnitude(double x, double y, bool c){
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

ppd vec2d::add(ppd x, ppd y) {
    return calculateMagnitude(x.first.first + y.first.first, x.first.second + y.first.second, 0);
}

ppd vec2d::multi(ppd x, ppd y) {
    return calculateMagnitude(x.first.first * y.first.first, x.first.second * y.first.second, 0);
}

ppd vec2d::divide(ppd x, ppd y) {
    return calculateMagnitude(x.first.first / y.first.first, x.first.second / y.first.second, 0);
}

ppd vec2d::sum(std::vector <ppd> v) {
    ppd ans = calculateMagnitude(0, 0, 0);
    for (auto i : v) {
        ans = vec2d::add(ans, i);
    }
    return ans;
}

double vec2d::angle_add(double x, double y) {
    if (x + y >= 2 * PI) {
        return x + y - 2 * PI;
    }
    return x + y;
}