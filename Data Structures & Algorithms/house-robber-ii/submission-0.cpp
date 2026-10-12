class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int x=hr(nums,0,n-2);
        int y = hr(nums,1,n-1);

        return max(a,b);
    }
    int hr(vector<int>& nums,int start,int end){
        int a=0;
        int b=0;

        int c;

        for(int i = start;i<=end;i++){
            c=max(a+nums[i],b);
            a=b;
            b=c;
        }
        return c;

    }
};
