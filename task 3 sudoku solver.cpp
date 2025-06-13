#include <iostream>
using namespace std;

#define N 9  

void printBoard(int board[N][N]) {
    cout << "\nSolved Sudoku Grid:\n";
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int board[N][N], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; ++x) {
        if (board[row][x] == num)
            return false;
    }

    for (int x = 0; x < N; ++x) {
        if (board[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row][col] == 0) { 
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board))
        printBoard(board);
    else
        cout << "No solution exists." << endl;

    return 0;
}
