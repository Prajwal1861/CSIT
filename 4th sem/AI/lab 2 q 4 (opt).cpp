#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        int qCol = board[i];
        if (qCol == col || abs(qCol - col) == abs(i - row))
            return false;
    }
    return true;
}

void printBoard(const vector<int>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << (board[i] == j ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int row, vector<int>& board, int n, int& count) {
    if (row == n) {
        ++count;
        cout << "Solution " << count << ":\n";
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(row + 1, board, n, count);
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N (4 to 8): ";
    cin >> n;

    if (n < 4 || n > 8) {
        cout << "Invalid input. Please enter a value between 4 and 8." << endl;
        return 1;
    }

    vector<int> board(n, -1);
    int solutionCount = 0;

    cout << "=== Solving " << n << "-Queens Problem ===\n";
    solveNQueens(0, board, n, solutionCount);
    cout << "Total Solutions for " << n << "-Queens: " << solutionCount << endl;

    return 0;
}

