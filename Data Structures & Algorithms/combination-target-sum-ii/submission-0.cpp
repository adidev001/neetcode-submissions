class Solution {
public:
    void bt(vector<int>& candidates, int target, int sum, vector<vector<int>>& res, vector<int>& arr, int index) {
        // 1. Base cases
        if (sum == target) {
            res.push_back(arr);
            return;
        }
        if (sum > target || index == candidates.size()) {
            return;
        }

        arr.push_back(candidates[index]);
        bt(candidates, target, sum + candidates[index], res, arr, index + 1);

        // 3. Backtrack
        arr.pop_back();

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }

        bt(candidates, target, sum, res, arr, index + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        
        sort(candidates.begin(), candidates.end());
        
        bt(candidates, target, 0, res, arr, 0);
        
        return res;
    }
};