/* 1.    
Use the multiplicative
congruential method to generate a sequence of four three-digit random integers, with seed = 117, constant multiplier = 43, and modulus = 1000. (4+6)    tu 2070

Hint:
X0=117,
a=43, c=0, and m=1000.
Xi+1=(aXi+c) mod m
R1=X1/m*/


#include <iostream>
using namespace std;

int main() {
    int X[5]; 
    double R[4]; 
    int a = 43;
    int c = 0;
    int m = 1000;

    X[0] = 117; 

    for(int i = 1; i <= 4; i++) {
        X[i] = (a * X[i-1] + c) % m;
        R[i-1] = (double)X[i] / m;\
    }

    cout << "Xi\tRi" << endl;
    for(int i = 1; i <= 4; i++) {
        cout << X[i] << "\t" << R[i-1] << endl;
    }

    return 0;
}

