class Solution {
public:
    void bt(int n, int k, vector<vector<int>>& res, vector<int>& arr, int index) {
        if (arr.size() == k) {
            res.push_back(arr);
            return;
        }
        if (index > n) {
            return;
        }
       
        arr.push_back(index);
        bt(n, k, res, arr, index + 1);

        arr.pop_back();
        bt(n, k, res, arr, index + 1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr;
        bt(n, k, res, arr, 1);
        return res;
    }
};