#include <string>
#include <vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        if (n <= 1) return s;

        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        int start = 0;
        int maxres = 1;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        int cl = j - i + 1;
                        if (cl > maxres) {
                            maxres = cl;
                            start = i;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxres);
    }
};