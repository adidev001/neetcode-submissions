class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxc = 0;
        vector<int> count(256, 0);
        int res = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            count[s[i]]++;
            maxc = max(maxc, count[s[i]]);
            while ((i - l + 1) - maxc > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};
