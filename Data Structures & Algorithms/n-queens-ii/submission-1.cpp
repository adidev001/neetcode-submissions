class Solution {
public:
    int totalNQueens(int n) {
        int limit = (1 << n) - 1;
        return solve(0, 0, 0, limit);
    }

private:
    int solve(int cols, int d1, int d2, int limit) {
        if (cols == limit) return 1;

        int count = 0;
        // Available spots: bits that are not attacked and within the board width
        int available = (~(cols | d1 | d2)) & limit;

        while (available > 0) {
            int p = available & (-available); // Extract lowest available column
            available &= (available - 1);     // Clear that bit

            // Recurse: d1 shifts left, d2 shifts right
            count += solve(cols | p, (d1 | p) << 1, (d2 | p) >> 1, limit);
        }

        return count;
    }
};