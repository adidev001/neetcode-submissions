class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        vector<int> dp(n+1);
        dp[n]=1;
        for(int i =n;i>=0;i--){
            if(num(s[i])<10){
            if(s[i]==0)dp[i]=0;
            else{
                dp[i]=dp[i+1];
            }}else if(num(s[i]*10+s[i+1])<=26 ||num(s[i]*10+s[i+1])>=10){
                dp[i]=dp[i+1]+dp[i+2];
            }
        }
    }return dp[0];
};
