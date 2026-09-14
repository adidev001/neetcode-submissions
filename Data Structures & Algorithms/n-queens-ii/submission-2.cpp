#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0; // 1. Initialized to 0
        vector<string> board(n, string(n, '.'));
        solve(board, count, 0);
        return count;
    }

    // 2. Passed by reference: int &count
    void solve(vector<string> &board, int &count, int row) {
        if (row == board.size()) {
            count++;
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (issafe(row, col, board)) {
                board[row][col] = 'Q';
                solve(board, count, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool issafe(int r, int c, const vector<string>& board) {
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }

        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};