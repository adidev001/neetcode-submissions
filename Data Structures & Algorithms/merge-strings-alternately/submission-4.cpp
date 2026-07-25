class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int l=0;
        int r=0;
        while(l<word1.length()&&r<word2.length()){
            res+=word1[l++];
            res+=word2[r++];
        }
        res+=word1.substr(l);
        res+=word2.substr(r);
        
        return res;
        
    }
};