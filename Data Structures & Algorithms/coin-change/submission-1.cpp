class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        // dp[i] will store the minimum coins needed for sub-amount i
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        // Iterate through all sub-amounts from 1 up to amount
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] was never updated, the target cannot be reached
        return dp[amount] > amount ? -1 : dp[amount];
    }
};