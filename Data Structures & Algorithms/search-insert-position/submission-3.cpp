class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        while(l<=r){
            int m=l+(r-1)/2;
            if(nums[m]>target){
                r=m-1;
                
            }else if(nums[m]<target){
                l=m+1;
                
            }else if(target==nums[m]){
                return m;
            }else{
                return m+1;
            }

        }
    }
};