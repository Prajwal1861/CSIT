/* If 2% of the products made in a company are defective. Find the probability that
less than 1 item is defective in the sample of 100 items.*/

#include <iostream>
#include <cmath>
using namespace std;

class PoissonDistribution {
private:
    int n;        // number of items
    double p;     // probability of defective
    double lambda; // mean (n * p)

public:
    // Constructor
    PoissonDistribution(int trials, double probability) {
        n = trials;
        p = probability;
        lambda = n * p; // mean of Poisson
    }

    // Function to calculate P(X = 0)
    double probabilityLessThanOne() {
        return exp(-lambda); // P(X=0) = e^(-lambda)
    }

    // Display result
    void displayResult() {
        cout << "Number of items (n): " << n << endl;
        cout << "Defective probability (p): " << p << endl;
        cout << "Mean (lambda = n*p): " << lambda << endl;
        cout << "Probability of less than 1 defective item (X < 1): "
             << probabilityLessThanOne() << endl;
    }
};

int main() {
    PoissonDistribution obj(100, 0.02); // 100 items, 2% defective
    obj.displayResult();
    return 0;
}

