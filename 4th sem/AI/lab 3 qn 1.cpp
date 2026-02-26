#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class NaiveBayes {
    map<string, int> classCounts;
    map<string, map<int, map<string, int>>> featureCounts;
    int totalSamples = 0;

public:
    void train(vector<vector<string>> X, vector<string> y) {
        for (int i = 0; i < X.size(); i++) {
            classCounts[y[i]]++;
            totalSamples++;
            for (int j = 0; j < X[i].size(); j++) {
                featureCounts[y[i]][j][X[i][j]]++;
            }
        }
    }

    string predict(vector<string> sample) {
        double bestProb = -1e9;
        string bestClass;
        for (auto& c : classCounts) {
            double logProb = log((double)c.second / totalSamples);
            for (int i = 0; i < sample.size(); i++) {
                int count = featureCounts[c.first][i][sample[i]] + 1; // Laplace smoothing
                int total = c.second + featureCounts[c.first][i].size();
                logProb += log((double)count / total);
            }
            if (logProb > bestProb) {
                bestProb = logProb;
                bestClass = c.first;
            }
        }
        return bestClass;
    }
};

int main() {
    vector<vector<string>> X = {{"sunny", "hot"}, {"rainy", "mild"}, {"overcast", "cool"}};
    vector<string> y = {"no", "yes", "yes"};

    NaiveBayes nb;
    nb.train(X, y);

    vector<string> test = {"sunny", "cool"};
    cout << "Prediction: " << nb.predict(test) << endl;
    return 0;
}

