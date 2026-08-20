class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        int count=0;
        int start=0;
        int next=0;
        for(int i=0;i<n-1;i++){
            start=intervals[i][0];
            next=intervals[i+1][0];
            if(start>=next)count++;


        }return count++;

    }
};
