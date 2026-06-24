class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int r= nums.size()-1;
        int midd;
        while(l<=r){
            int min = (l+r)/2;{
                if(nums[min]>nums[r]){
                    l=min+1;

                }else if(nums[min]>nums[l])r=mid-1;
            }else{
                midd=nums[min];
                return midd;
            }
        }


    }
};
