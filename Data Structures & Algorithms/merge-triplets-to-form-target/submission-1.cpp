class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector <int> flag(3,0);

        for(auto triplet:triplets){
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[3]){
                if(triplet[0]==target[0])flag[0]=1;
                 if(triplet[1]==target[1])flag[1]=1;
                  if(triplet[2]==target[2])flag[2]=1;
            }
        }

        for(auto it: flag){
            if(it==0)return false;
        }
        return true;
        
    }
};
