class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        int a=0;
        int b=0;
        int c;

        for (int i=2;i<=n;i++){
            c=min(a+cost[i-1],b+cost[i-2]);
            a=b;
            b=c;



        }
        return c;


    }
};
