class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n= s.length()-1;
        queue <int>q;
        if (s.back() == '1') return false;
        q.push(0);
        int farthest =0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            if(curr==n){
                return true;
            }

            int left= max(curr+minJump,farthest);
            int right=min(curr+maxJump,n-1);

            for(int i=left;i<=right;i++){
                if(s[i]=='0'){
                    q.push(i);
                }
            }

            farthest=max(farthest ,curr+maxJump);


        }return false;

    }
};