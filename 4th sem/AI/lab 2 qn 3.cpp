   #include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

// Depth-limited Minimax function

int minimax(int depth, int nodeIndex, bool isMax, vector<int>& scores, int height) {

    if (depth == height)

        return scores[nodeIndex];

    if (isMax) {

        return max(

            minimax(depth + 1, nodeIndex * 2, false, scores, height),

            minimax(depth + 1, nodeIndex * 2 + 1, false, scores, height)

        );

    } else {

        return min(

            minimax(depth + 1, nodeIndex * 2, true, scores, height),

            minimax(depth + 1, nodeIndex * 2 + 1, true, scores, height)

        );

    }

}

int main() {

    // Leaf node values from H to S: 2, 4, 6, 9, 1, 2, 7, 5

    vector<int> scores = {2, 4, 6, 9, 1, 2, 7, 5};

    int height = 3; // 3 levels from root to leaves (A ? B/C ? D/E/F/G ? H...S)

    int optimalValue = minimax(0, 0, true, scores, height);

    cout << "The optimal value is: " << optimalValue << endl;

    return 0;

}

}
}
