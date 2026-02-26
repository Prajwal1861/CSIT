#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to print a single solution
void printSolution(const vector<int>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Check if it's safe to place a queen at row 'row' and column 'col'
bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Backtracking function to solve the problem
void solveNQueens(int n, int row, vector<int>& board, int& solutionCount) {
    if (row == n) {
        solutionCount++;
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(n, row + 1, board, solutionCount);
        }
    }
}

// Main driver
int main() {
    for (int n = 4; n <= 8; ++n) {
        cout << "Solving " << n << "-Queens Problem:\n";
        vector<int> board(n, -1);
        int solutionCount = 0;
        solveNQueens(n, 0, board, solutionCount);
        cout << "Total solutions for " << n << "-Queens: " << solutionCount << "\n\n";
    }

    return 0;
}

