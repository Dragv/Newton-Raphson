#include <iostream>
#include <cmath>

#define ITER 1000
#define MINERR 1E-15

using namespace std;

typedef double (* vFunctionCall)(double x);

double function1(double x) {
    return x*x*x+5*x-10;
}

double functionDerivative (double x){
    return 3*x*x+5;
}

float tangenteMethod(vFunctionCall funct, vFunctionCall deri, float a){
    float x0 = a;
    double y = funct(x0);
    int i = 1;
    do{
        if (deri(x0) == 0){
            throw invalid_argument("Math error");
        }

        float x1 = x0 - (funct(x0)/deri(x0));
        x0 = x1;

        if (i > ITER){
            return x0;
        }
        x0 = x0 - (y/deri(x0));
        y = funct(x0);
        i++;
        if (i > ITER){
            return  x0;
        }
        i++;
    } while (abs(funct(x0)) > MINERR);
    return x0;
}

int main() {

    cout << tangenteMethod(function1, functionDerivative, 10);

    return 0;
}
