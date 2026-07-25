class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int l=0;
        int n=height.size();
        int r=n-1;
        int leftmax=0;
                    int rightmax=0;

        while(l<r){
            
            leftmax=max(height[l],leftmax);
            rightmax=max(height[r],rightmax);
            if(leftmax<rightmax){
                ans+=leftmax-height[l];
                l++;
            }else{
                ans+=rightmax-height[r];
                r--;
            }
        }return ans;
    }
};