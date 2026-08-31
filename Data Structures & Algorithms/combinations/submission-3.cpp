class Solution {
   public:
    void bt(int n, int k, vector<vector<int>> res, vector<int> arr, int index) {
        if (int k == arr.size()) {
            res.push_back(arr);
            return;
        }
        if (index == n || no>n) {
            return;
        }


        arr.push_back(index);
        
        bt(n,k,res,arr,index+1);

        arr.pop_back();
        bt(n,k,res,arr,index);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr;
        int index=1;

        bt(n, k, res, arr, index);
        return res;
    }
};