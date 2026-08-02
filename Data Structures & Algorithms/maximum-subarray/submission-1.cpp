class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=num[0];
        int currsum=0;
        for(auto it:nums){
            if(currsum<0){
                currsum=0;
            }

            currsum+=it;
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};
