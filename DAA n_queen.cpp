#include <iostream>
using namespace std;

int count = 0;

void pBoard(char board[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

bool isSafe(char board[][10], int row, int col, int n) {
    // Check vertically above
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void qPlace(char board[][10], int row, int n) {
    if (row == n) {
        count++;
        pBoard(board, n);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            qPlace(board, row + 1, n);
            board[row][j] = 'X';  // Backtrack
        }
    }
}

int main() {
    int n = 8;  // 8 queens
    char board[10][10];

    // Initialize the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 'X';
        }
    }
    board[0][0]='Q';

    // Start placing queens from the first row without fixing the first queen
    qPlace(board, 1, n);  // Start from the first row

    cout << "Number of ways queens can be placed are " << count << endl;

    return 0;
}
