class Solution {
   public:
    void bt(vector<int>& nums, int target, int sum, vector<vector<int>>& res, vector<int>& arr,
            int index) {
        if (sum == target) {
            res.push_back(arr);
            return;
        }
        if (index == nums.size()) {
            return;
        }
        if (sum > target) {
            return;
        }
        arr.push_back(nums[index]);

        bt(nums, target, sum + nums[index], res, arr, index);
        arr.pop_back();

        bt(nums, target, sum, res, arr, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        int index;
        bt(nums, target, 0, res, arr, 0);
        return res;
    }
};
