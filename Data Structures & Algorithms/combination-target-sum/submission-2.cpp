class Solution {
public:
    void bt(vector<int>& nums, int target,int sum,vector<vector<int>>&res,vector<int>&arr,int index){

        if(sum==target)res.push_back(arr);
        if(index==nums.size())return;
        if(sum>target)return;


        bt(nums,index,sum+=arr[index]);
        arr.push_back(nums[index]);

        bt(nums,index+1,sum);
        arr.pop_back(nums[index]);


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>arr;
        int index;
        bt(nums,target,0,res,arr,0);
        return res;
    }
};
