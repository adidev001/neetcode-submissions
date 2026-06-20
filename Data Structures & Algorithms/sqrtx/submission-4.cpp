class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x/2;
        int res;
        while(l<=r){
            int m=l+(r-1)/2;
            if(m*m == x)return m;
            else if(m*m>x){
                if(m-1*m-1<target)return m-1;
                r=m-1;

            }else{
                l=m+1;
                res=m;
            }
        }return res;
    }
};