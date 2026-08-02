class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l=0;
        int r=1;
        int res=1;
        int n=arr.size();
        string prev="";

        while(r<n){
            if(arr[r-1]>arr[r] && prev!=">"){
                res =max(res,r-l+1);
                r++;
                prev=">";
            }
            else if(arr[r-1]<arr[r] && prev!="<"){
                res =max(res,r-l+1);
                r++;
                prev=">";
            }
            else {
                
                if(arr[r-1]==arr[r]){
                    l=r;
                    r++;
                    prev="";
                }else{
                    l=r-1;
                    prev=""
                }
            }
        }return res;
        
    }
};