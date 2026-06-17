class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1=s1.size();
        int len2=s2.size();

        vector<int>count(26,0);
        vector<int>count1(26,0);

        for(int i=0;i<len1;i++){
            count[s1[i]-'a']++;
        }

        if(len2<len1)return false;
        int l=0;
        for(int r=0;r<len1;r++){
            count1[s2[r]-'a']++;
            
            if(r-l+1>len1){
                count1[s2[l]]--;
                l++;
            }
            if(r-l+1==len1){
                if(count.size()==count1.size()){
                    return true;
                }
            }
        }return false;


    }
};
