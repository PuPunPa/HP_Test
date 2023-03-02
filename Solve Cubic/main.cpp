#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double Solve(int a, int b, int c, int d, double x){
    double fx = (a*pow(x, 3) + b*pow(x, 2) + c*x + d);
    return fx;
}

int main(int argc, char** argv){
    if(argc != 5){
        cout << "Command is missing " << 5-argc << ((5-argc > 1) ? " arguments, please try again." : " argument, please try again.");
        return 0;
    }
    int a, b, c, d;
    sscanf(argv[1], "%d", &a);
    sscanf(argv[2], "%d", &b);
    sscanf(argv[3], "%d", &c);
    sscanf(argv[4], "%d", &d);
    int x=0;
    cout << "(" << argv[1] << "x3) + (" << argv[2] << "x2) + (" << argv[3] << "x) + (" << argv[4] << ") = 0" << endl;
    cout << "{ ";
    while(true){
        int fx = Solve(a, b, c, d, x);
        if(fx == 0){
            cout << x <<", ";
        }
        else if(fx < 0){
            break;
        }
        x--;
    }
    x=1;
    while(true){
        int fx = Solve(a, b, c, d, x);
        if(fx == 0){
            cout << x <<", ";
        }
        else if(fx > 0){
            break;
        }
        x++;
    }
    cout << "}";
    return 0;
}