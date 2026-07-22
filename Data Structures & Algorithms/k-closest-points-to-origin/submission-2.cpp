class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;

        for(auto point:points){
            int dist= point[0]*point[0]+point[1]*point[1];

            pq.push({dist,point});

            while(pq.size()>k){
                pq.pop();
            }
        
        }
        vector<vector<int>> res;
        while(pq.empty()){
            vector<int>temp;
            temp.push_back(pq.top());
            res.push_back(temp);
            pq.pop();
        }
        return res;
    
    }

};
