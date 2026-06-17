class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxc=0;
        vector<int>count(256,0);
        for(int i=0;i<n;i++){
            count[s[i]]++;
            maxc=max(maxc,count[s[i]]);

        }return maxc+k;

    }
};
