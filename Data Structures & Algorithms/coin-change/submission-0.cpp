class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0)return 0;
        sort(coins.begin(),coins.end());
        vector<int> dp(aount+1,amount+1);
        dp[0]=0;
        int n = coins.size();

        for (int i=1;i<=n;i++){
            for(auto coin:coins){
                if(i-coins>=0){
                    dp[i]=min(dp[i],1+dp[i-1]);
                }
            }
        }
        return dp[n];
        
    }
};
