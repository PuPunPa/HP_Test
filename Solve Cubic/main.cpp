#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double Solve(int a, int b, int c, int d, int x){
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
    int turns = 0;
    int roots[3];
    cout << "(" << argv[1] << "x3) + (" << argv[2] << "x2) + (" << argv[3] << "x) + (" << argv[4] << ") = 0" << endl;
    
    for(int i = 0; i < 1000000; i++){
        int fxFromLeft = Solve(a, b, c, d, -i);
        int fxFromRight = Solve(a, b, c, d, i+1);
        if(fxFromRight == 0){
            cout << "fx(" << i+1 << "): " << fxFromRight << endl;
            roots[turns] = i+1;
            turns++;
        }
        if(fxFromLeft == 0){
            cout << "fx(" << -i << "): " << fxFromRight << endl;
            roots[turns] = -i;
            turns++;
        }
    }

    cout << "{";
    for(int i = 0; i < turns; i++){
        cout << roots[i] << ", ";
    }
    cout << "}" << endl;
    return 0;
}