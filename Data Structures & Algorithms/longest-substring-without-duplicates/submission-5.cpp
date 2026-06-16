class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        set<int> set;
        int l=0;
        int r=0;
        int maxs=0;
        while(r<n){
            while(set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            maxs=max(maxs,r-l+1);
            r++;
        }
        return maxs;
    }
};
