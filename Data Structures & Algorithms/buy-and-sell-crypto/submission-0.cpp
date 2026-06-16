class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxp=0;
        for(int b=0;b<n-1;b++){
            int s=i+1;
            if(arr[b]<=arr[s]&&j<n){
                maxp=max(max,arr[s]-arr[b]);
                s++;
            }else{
                s++;
            }
        }

        return maxp;
    }
};
