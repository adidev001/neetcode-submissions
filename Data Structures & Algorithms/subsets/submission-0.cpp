class Solution {
public:

   void bt(int index,vector<int>& nums,vector<vector<int>>res,vector<int>sub){
        if(index==nums.size()){
            res.push_back(subset);
            return res;
        }

        sub.push_back(nums[index]);
        bt(index+1,nums,res,sub);

        sub.pop();
        bt(index+1,nums,res,sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>sub;
        bt(0,nums,res,sub);
        return res;
    }
};
