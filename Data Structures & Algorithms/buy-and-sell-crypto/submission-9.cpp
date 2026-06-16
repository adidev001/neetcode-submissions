class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxp = 0;
        int i=0,r=1;


        while(r<n){
            if(prices[i]<prices[r]){
                maxp=max(maxp,prices[r]-prices[i]);

            }else{
                i=r;
            }r++;
        }
        return maxp;
    }
};
