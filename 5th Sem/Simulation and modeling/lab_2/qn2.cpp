/* The sequence of numbers 0.54, 0.73, 0.98, 0.11 and 0.68 has been generated. 
Use the Kolmogorov-Smirnov test with level of significance 
(a) 0.05 to determine if the hypothesis that the numbers are uniformly 
distributed on the interval 0 to 1 can be rejected. (Note that the value of D for a = 0.05 ans N = 5 is 0.565).*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    double numbers[] = {0.54, 0.73, 0.98, 0.11, 0.68};
    int N = 5;
    double D_alpha = 0.565;

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
    for(int i = 0; i < N; i++) cout << numbers[i] << " ";
    cout << endl;
    cout << "D+ = " << D_plus << endl;
    cout << "D- = " << D_minus << endl;
    cout << "D = " << D << endl;

    if(D < D_alpha)
        cout << "D < D_alpha => Cannot reject H0. Numbers are uniformly distributed." << endl;
    else
        cout << "D >= D_alpha => Reject H0. Numbers are not uniformly distributed." << endl;

    return 0;
}

