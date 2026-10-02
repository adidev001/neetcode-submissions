class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;

        char temp;

        while(l<r){
            temp=char[l];
            char[l++]=char[r];
            char[r--]=temp;
        }

    }
};