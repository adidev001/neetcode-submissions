class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxp=0;
        for(int b=0;b<n-1;b++){
            int s=b+1;
            if(prices[b]<=prices[s]&&j<n){
                maxp=max(max,prices[s]-prices[b]);
                s++;
            }else{
                s++;
            }
        }

        return maxp;
    }
};
