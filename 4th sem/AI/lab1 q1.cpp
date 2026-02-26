#include <iostream>
#include <vector>
using namespace std;

char board[3][3];

// Function to initialize the board
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to print the current board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Check for winner
char checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Rows
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0];
        // Columns
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return board[0][i];
    }
    // Diagonals
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}

// Check if board is full
bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Check if a player can win in the next move
pair<int, int> findWinningMove(char player) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (checkWinner() == player) {
                    board[i][j] = ' ';
                    return {i, j};
                }
                board[i][j] = ' ';
            }
        }
    return {-1, -1};
}

// AI move using rule-based strategy
void aiMove() {
    cout << "AI's move (X):\n";

    // 1. Win if possible
    pair<int, int> move = findWinningMove('X');
    if (move.first != -1) {
        board[move.first][move.second] = 'X';
        return;
    }

    // 2. Block if player is about to win
    move = findWinningMove('O');
    if (move.first != -1) {
        board[move.first][move.second] = 'X';
        return;
    }

    // 3. Take center if available
    if (board[1][1] == ' ') {
        board[1][1] = 'X';
        return;
    }

    // 4. Take a corner
    vector<pair<int, int>> corners = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (auto c : corners) {
        if (board[c.first][c.second] == ' ') {
            board[c.first][c.second] = 'X';
            return;
        }
    }

    // 5. Take any side
    vector<pair<int, int>> sides = {{0,1}, {1,0}, {1,2}, {2,1}};
    for (auto s : sides) {
        if (board[s.first][s.second] == ' ') {
            board[s.first][s.second] = 'X';
            return;
        }
    }
}

// Human move
void humanMove() {
    int row, col;
    cout << "Your move (O). Enter row and column (0, 1, 2): ";
    while (true) {
        cin >> row >> col;
        if (cin.fail() || row < 0 || row > 2 || col < 0 || col > 2) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter row and column between 0 and 2: ";
        } else if (board[row][col] != ' ') {
            cout << "Cell already occupied. Try again: ";
        } else {
            break;
        }
    }
    board[row][col] = 'O';
}

int main() {
    initBoard();
    printBoard();

    while (true) {
        aiMove();
        printBoard();
        if (checkWinner() == 'X') {
            cout << "AI wins!\n";
            break;
        }
        if (isBoardFull()) {
            cout << "It's a draw!\n";
            break;
        }

        humanMove();
        printBoard();
        if (checkWinner() == 'O') {
            cout << "You win!\n";
            break;
        }
        if (isBoardFull()) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}

