class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;

        int n=hand.size();
        vector<int>visit(n,0);
        int count=0;
        int i=0;
        visit[i]=1;
        int group=0;
        vector<int>skip;

        while(i<n){
            if(hand[i]+1==hand[i+1] && visit[i+1]==0){
                visit[i+1]=1;
                count++;
                if(count==groupSize){
                    count=0;
                    group++;
                    i=skip.erase(skip.begin());
                }
                i++;
            }else{
                skip.push_back(i);
                i++;
            }
        }
        if(group==n/groupSize)return true;
        return false;

        
    }
};
