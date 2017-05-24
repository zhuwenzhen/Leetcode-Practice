//
//  main.cpp
//  NewtonMethod
//
//  Created by Wenzhen Zhu on 3/15/17.
//  Copyright © 2017 Wenzhen Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

using namespace std;

class NewtonMethod{
public:
    using func = double(*)(double);
    
    double newtonStep (func f, func df, double x){
        return x - f(x) / df(x);
    }
    
    vector<double> newtonArray (func f, func df, double x0, int n){
        vector<double> x(n);
        x[0] = x0;
        
        for(int k = 0; k < n; k++ ){
            x[k+1] = newtonStep(f, df, x[k]);
        }
        return x;
    }
    
    double newtonMethod(func f, func df, double x0, double epsilon){
        double xt;
        while(true){
            xt = newtonStep(f, df, x0);
            if(abs(xt - x0) <= epsilon) break;
            x0 = xt;
        }
        return xt;
    }
};

double f (double x){
    return pow(x,2) - 2;
}

double df(double x){
    return 2*x;
}

int main(int argc, const char * argv[]) {
    NewtonMethod newton;

    vector<double> xs = newton.newtonArray(f, df, 3, 5);
    
    for(auto e: xs){
        cout << e << " ";
    }
    cout << endl;
    
    double xt = newton.newtonMethod(f, df, 3, 10e-6);
    cout << xt << endl;
    return 0;
}
