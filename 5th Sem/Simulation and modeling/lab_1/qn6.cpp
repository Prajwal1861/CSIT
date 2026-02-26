/* Customers arrive in a bank according to a Poisson&#39;s process with mean inter
arrival time of 10 minutes. Customers spend an average of 5 minutes on the
single available counter, and leave.
a. Probability that a customer will not have to wait at the counter.
b. Expected number of customers in the bank.
c. Time a customer expects to spend in the bank. */

#include <iostream>
using namespace std;

class BankQueue {
private:
    double meanInterArrivalTime;
    double meanServiceTime;
    double lambda;   // arrival rate
    double mu;       // service rate
    double rho;      // traffic intensity

public:
    // Constructor
    BankQueue(double interArrival, double serviceTime) {
        meanInterArrivalTime = interArrival;
        meanServiceTime = serviceTime;

        lambda = 1.0 / meanInterArrivalTime;
        mu = 1.0 / meanServiceTime;
        rho = lambda / mu;
    }

    // a) Probability that a customer will not have to wait
    double probabilityNoWait() {
        return 1 - rho;
    }

    // b) Expected number of customers in the bank
    double expectedCustomers() {
        return rho / (1 - rho);
    }

    // c) Expected time spent in the bank
    double expectedTimeInBank() {
        return 1 / (mu - lambda);
    }
};

int main() {
    // Mean inter-arrival time = 10 minutes
    // Mean service time = 5 minutes
    BankQueue bank(10.0, 5.0);

    cout << "Probability that a customer will not wait: "
         << bank.probabilityNoWait() << endl;

    cout << "Expected number of customers in the bank: "
         << bank.expectedCustomers() << endl;

    cout << "Expected time spent in the bank: "
         << bank.expectedTimeInBank() << " minutes" << endl;

    return 0;
}

