class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      
        sort(nums.begin(), nums.end()); 
        dfs(0, nums);
        return res;
    }

    void dfs(int i, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> seen; 
        
        for (int j = i; j < nums.size(); ++j) {
            if (seen.count(nums[j])) {
                continue;
            }
            
            seen.insert(nums[j]); 
            
            swap(nums[i], nums[j]); 
            dfs(i + 1, nums);       
            swap(nums[i], nums[j]); 
        }
    }
};