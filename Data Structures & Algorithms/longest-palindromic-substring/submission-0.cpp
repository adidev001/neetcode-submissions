class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        vector<vector<bool>>dp(n,vector<int>(n,bool));

        int start =0;
        int maxres=1;

        for(int i =n-1;i<=0;i--){
            for(int j=0;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=2 || dp[i+1][j-1]){
                        dp[i][j]=true;
                        int cl=j-i+1;
                        if(cl>maxres){maxres=cl;
                        start=i;}
                    }
                }
            }
        }
    }return s.substr(start,maxres);
};
