class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        for(int i=0;i<=r;i++){
            if(isalnum(s[i])){
                s[l]=tolower(s[i]);
                l++;
            }
        }
        int le=0;
        int ri= l-1;
        while(le<ri){
            while(s[le]!=s[ri])return false;
            le++,ri--;
        }
        // while(l<r){
        //     while(l>r&&isalnum(s[l]))l++;
        //     while(l<r&&isalnum(s[r]))r--;
        //     while(tolower(s[l])!=tolower(s[r]))return false;
        //     l++,r--;
        // }return true;//neetcode
        return true;
        
        
    }
};