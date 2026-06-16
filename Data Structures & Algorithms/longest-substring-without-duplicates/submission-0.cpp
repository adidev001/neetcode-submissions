class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        set<int> set;
        int l=0;
        int r=0;
        while(r<n){
            if(set.find(s[r])!=set.end()){
                set.insert();
                r++;
            }else{
                set.erase(s[l]);
                l++;

            }
        }
        return set.size();
    }
};
