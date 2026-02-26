#include <iostream>
using namespace std;

int main() {
    const int n = 25;
    const int m = 5;

    double data[n] = {
        0.08, 0.12, 0.95, 0.34, 0.11,
        0.56, 0.77, 0.21, 0.04, 0.66,
        0.43, 0.19, 0.82, 0.55, 0.27,
        0.03, 0.99, 0.41, 0.15, 0.60,
        0.88, 0.32, 0.14, 0.71, 0.22
    };

    double sum = 0.0;

    for(int k = 0; k < n - m; k++) {
        sum += data[k] * data[k + m];
    }

    double r = sum / (n - m);

    cout << "Autocorrelation coefficient (lag 5) = " << r << endl;

    return 0;
}

