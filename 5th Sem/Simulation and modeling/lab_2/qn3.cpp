/* 3.    
For the following sample of random numbers, perform test for independence using K-S test. (D0.05,10 = 0.41)
0.35, 0.77, 0.12, 0.33, 0.88, 0.45, 0.19, 0.25, 0.91, 0.54  
(tu 2081) */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double numbers[] = {0.35, 0.77, 0.12, 0.33, 0.88, 0.45, 0.19, 0.25, 0.91, 0.54};
    int N = 10;
    double D_alpha = 0.41;

    sort(numbers, numbers + N);

    double D_plus = 0.0, D_minus = 0.0;

    for(int i = 0; i < N; i++) {
        double d_plus = (double)(i+1)/N - numbers[i];
        double d_minus = numbers[i] - (double)i/N;
        if(d_plus > D_plus) D_plus = d_plus;
        if(d_minus > D_minus) D_minus = d_minus;
    }

    double D = max(D_plus, D_minus);

    cout << "Sorted sequence: ";
    for(int i=0;i<N;i++) cout << numbers[i] << " ";
    cout << endl;
    cout << "D+ = " << D_plus << endl;
    cout << "D- = " << D_minus << endl;
    cout << "D = " << D << endl;

    if(D < D_alpha)
        cout << "D < D_alpha => Cannot reject H0. Numbers are independent." << endl;
    else
        cout << "D >= D_alpha => Reject H0. Numbers are not independent." << endl;

    return 0;
}

