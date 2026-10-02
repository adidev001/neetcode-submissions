class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=0;

        for (int i=2;i<=n;i++){
            dp[i]=min(dp[n-1]+cost[n-1],dp[n-2]+cost[n-2]);

        }
        return dp[n];


    }
};
