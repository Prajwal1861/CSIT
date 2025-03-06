/*2. Verify Modus Ponens using the truth table*/

#include <iostream>

using namespace std;

void printTruthTable() {
    cout << "P\tQ\tP -> Q\tP and (P -> Q)\tConclusion Q" << endl;

    bool P, Q;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            P = i;
            Q = j; 

            bool implication = (!P || Q);

            bool modusPonensCondition = P && implication;

            cout << P << "\t" << Q << "\t" << implication << "\t" << modusPonensCondition << "\t\t" << Q << endl;
        }
    }
}

int main() {
    printTruthTable();

    return 0;
}
