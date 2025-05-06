#include <bits/stdc++.h>
using namespace std;

// ========== Original Backtracking ==========

bool isSafe(int row, int col, const vector<vector<int>> &board, int n) {
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 1 || board[i][col] == 1)
            return false;
    }
    // Top-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;
    // Bottom-right diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1) return false;

    // Top-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1) return false;
    // Bottom-left diagonal
    for (int i = row, j = col; i < n && j < n; i++, j++)
        if (board[i][j] == 1) return false;

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int col, int n) {
    if (col >= n)
        return true;

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            if (solveNQueens(board, col + 1, n))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void printSolution(const vector<vector<int>> &board) {
    for (const auto &row : board) {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
    cout << endl;
}

// ========== Branch and Bound  ==========

void solveBB(int col, int n,
             vector<vector<int>> &board,
             vector<bool> &row, vector<bool> &diag1, vector<bool> &diag2,
             vector<vector<vector<int>>> &solutions) {
    if (col == n) {
        solutions.push_back(board);
        return;
    }

    for (int r = 0; r < n; r++) {
        if (!row[r] && !diag1[r + col] && !diag2[n - 1 + col - r]) {
            board[r][col] = 1;
            row[r] = diag1[r + col] = diag2[n - 1 + col - r] = true;

            solveBB(col + 1, n, board, row, diag1, diag2, solutions);

            board[r][col] = 0;
            row[r] = diag1[r + col] = diag2[n - 1 + col - r] = false;
        }
    }
}

// ========== Main ==========

int main() {
    int n;
    cout << "Enter the board size (n): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    cout << "\n--- Using Backtracking ---\n";
    if (solveNQueens(board, 0, n)) {
        cout << "Solution exists:\n";
        printSolution(board);
    } else {
        cout << "No solution exists\n";
    }

    cout << "\n\n--- Using Branch and Bound ---\n";
    vector<vector<int>> boardBB(n, vector<int>(n, 0));
    vector<bool> row(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
    vector<vector<vector<int>>> solutions;

    solveBB(0, n, boardBB, row, diag1, diag2, solutions);

    if (solutions.empty()) {
        cout << "No solution exists\n";
    } else {
        cout << solutions.size() << " solution(s):\n\n";
        for (const auto &sol : solutions)
            printSolution(sol);
    }

    return 0;
}