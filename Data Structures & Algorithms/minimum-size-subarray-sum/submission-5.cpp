class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int minm = INT_MAX; 
        int sum = 0;
        
        for(int r = 0; r < n; r++) {
            sum += nums[r];
            
            while(sum >= target) {
                minm = min(minm, r - l + 1); 
                sum -= nums[l];
                l++;
            }
        }
        
        return minm == INT_MAX ? 0 : minm;
    }
};