#include <iostream>
using namespace std;

int main() {
    const int n = 20;
    const int i = 4;   // starting position
    const int m = 2;   // lag

    double data[n] = {
        0.50, 0.11, 0.23, 0.76, 0.44,
        0.82, 0.19, 0.55, 0.33, 0.91,
        0.02, 0.67, 0.48, 0.12, 0.59,
        0.31, 0.88, 0.05, 0.74, 0.26
    };

    double sum = 0.0;
    int count = 0;

    // convert starting position to index (4th ? index 3)
    for(int k = i - 1; k + m < n; k += m) {
        sum += data[k] * data[k + m];
        count++;
    }

    double r = sum / count;

    cout << "Autocorrelation coefficient = " << r << endl;

    return 0;
}

