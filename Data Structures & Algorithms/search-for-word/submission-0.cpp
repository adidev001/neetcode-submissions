class Solution {
public:
    bool helper(vector<vector<char>>& board, const string& word, int i, int j, int k, int n, int m) {
        if (k == word.length()) return true;

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = helper(board, word, i + 1, j, k + 1, n, m) ||
                     helper(board, word, i - 1, j, k + 1, n, m) ||
                     helper(board, word, i, j + 1, k + 1, n, m) ||
                     helper(board, word, i, j - 1, k + 1, n, m);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, i, j, 0, n, m)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};