class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        while(l<=r){
            int m=l+(r-1)/2;
            if(nums[m]>target){
                if(target>nums[m-1])return m-1;
                r=m-1;
                
            }else if(nums[m]<target){
                if(target<nums[m+1])return m+1
                l=m+1;
                
            }else {
                return m;
            }

        
    }return 0;
    
}
};