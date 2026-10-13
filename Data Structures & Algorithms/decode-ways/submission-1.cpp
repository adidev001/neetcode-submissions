class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int next1 = 1; // represents dp[i + 1], base case dp[n] = 1
        int next2 = 0; // represents dp[i + 2]

        for (int i = n - 1; i >= 0; i--) {
            int current = 0;

            if (s[i] != '0') {
                current = next1;
                if (i + 1 < n) {
                    int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (twoDigit >= 10 && twoDigit <= 26) {
                        current += next2;
                    }
                }
            }

            next2 = next1;
            next1 = current;
        }

        return next1;
    }
};