class Solution {
   public:
    bool makesquare(vector<int>& matchsticks) {
        long long total = 0;
        for (int m : matchsticks) total += m;

        if (total % 4 != 0) return false;  
        long long target = total / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());  
        if (matchsticks[0] > target) return false;

        vector<long long> sides(4, 0);
        return dfs(matchsticks, 0, sides, target);
    }

    bool dfs(vector<int>& m, int i, vector<long long>& sides, long long target) {
        if (i == (int)m.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target &&
                   sides[3] == target;
        }
        for (int s = 0; s < 4; s++) {
            if (sides[s] + m[i] > target) continue;           // prune: overflow
            // prune: duplicate bucket
            sides[s] += m[i];
            if (dfs(m, i + 1, sides, target)) return true;
            sides[s] -= m[i];  // backtrack
        }
        return false;
    }
};