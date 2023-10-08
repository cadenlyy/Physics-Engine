#include<bits/stdc++.h>
#include<math.h>
#include <stdlib.h>

#include "constants.h"

using namespace std;
#define int long long
#ifndef Vector_functions_H_
#define Vector_functions_H_

typedef pair<double, double> pd;
typedef pair<pd,pd> ppd;

class vec2d{
    public:
        ppd magnitude;
        ppd calculateMagnitude(double x, double y, bool c){
            if (c == false){
                if(x == 0 and y == 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),0}};
                }
                if(x == 0 and y >= 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),0}};
                }
                if(x >= 0 and y == 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI/2}};
                }
                if(x == 0, y <= 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI}};
                }
                if(x <= 0, y == 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI*3/2}};
                }
                if(x > 0 and y > 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),atan(x/y)}};
                }
                if(x > 0 and y < 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI/2-atan(x/y)}};
                }
                if(x < 0 and y < 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI+atan(x/y)}};
                }
                if(x < 0 and y > 0){
                    return {{x,y},{sqrt(pow(abs(x),2)+pow(abs(y),2)),PI*2-atan(x/y)}};
                }
            }
            return {{x*sin(y),x*cos(y)},{x,y}};
        }
        ppd vec2dadd(ppd x, ppd y){
            return calculateMagnitude(x.first.first+y.first.first,x.first.second+y.first.second,0);
        }
        ppd vec2dmulti(ppd x, ppd y){
            return calculateMagnitude(x.first.first*y.first.first,x.first.second*y.first.second,0);
        }
        ppd vec2ddivide(ppd x, ppd y){
            return calculateMagnitude(x.first.first/y.first.first,x.first.second/y.first.second,0);
        }
        ppd vec2dsum(vector <ppd> v){
            ppd ans = calculateMagnitude(0,0,0);
            for(auto i: v){
                ans = vec2dadd(ans,i);
            }
            return ans;
        }
        double angle_add(double x, double y){
            if(x+y >= 2*PI){
                return x+y-2*PI;
            }
            return x+y;
        }
};

#endif