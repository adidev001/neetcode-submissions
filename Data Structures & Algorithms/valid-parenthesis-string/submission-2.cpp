class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int count =0
        int star=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            if(s[i]=='*'){
                star++;
            }
            if(s[i]==')'){
                count--;
            }

            if(i==n-1){
                if(count!=0 && star!=0){
                    if(star>count){
                        return true;
                }

             
            }
        }}
        return false;
    }
};
