#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int n = 2000;

    // Observed frequencies
    double O[5] = {1010, 860, 90, 35, 5};

    // Probabilities
    double P[5] = {0.504, 0.432, 0.027, 0.036, 0.001};

    double chi = 0;

    cout << "Category\tO\tE\t(O-E)^2/E\n";

    for(int i=0;i<5;i++) {
        double E = n * P[i];
        double value = pow(O[i]-E,2)/E;
        chi += value;

        cout << i+1 << "\t\t"
             << O[i] << "\t"
             << E << "\t"
             << value << endl;
    }

    cout << "\nChi-square = " << chi << endl;

    if(chi > 9.49)
        cout << "Reject H0 ? Numbers are NOT independent\n";
    else
        cout << "Fail to reject H0 ? Numbers are independent\n";

    return 0;
}

