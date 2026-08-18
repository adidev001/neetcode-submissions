class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int count =0,countt=0;
        int star=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            if(s[i]=='*'){
                star++;
            }
            if(s[i]==')'){
                countt++;
            }

            if(i==n-1){
               if(countt==count || countt<count && star>=count){
                        return true;
            

            }
        }
        }
        return false;
    }
};
