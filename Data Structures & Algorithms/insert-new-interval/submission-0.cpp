class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;

        int n= intervals.size();

        for(int i=0;i<n;i++){
            if(intervals[i][1]<newInterval[1])res.push_back(interval[i]);

            else if(intervals[i][0]>newInterval[1])res.push_back(newInterval);res.push_back(intervals[i]);
        }
        else{
            newInterval[0]=min(vec[i][0],interval[0]);
                        newInterval[1]=max(intervals[i][1]<newInterval[1]);


        }
        return res;
    }
};
