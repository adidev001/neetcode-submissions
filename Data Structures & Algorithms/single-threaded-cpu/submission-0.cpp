class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<array<long long,3>>main;
        long long index=0;
        long long currtime=0;
        for(auto a:tasks){
            main.push_back({a[0],a[1],index++});

        }
        sort(main.begin(),main.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int >result;
        int n=main.size();
        
        int i=0;
        while(i<n||!pq.empty()){
            if(pq.empty()||main[i][0]>currtime){
                currtime=main[i][0];
            }

            while(i<n||main[1][0]<=currtime){
                pq.push({main[i][0],main[i][1]});
                i++;
            }

            auto [processtime,orignalindex]= pq.top();pq.pop()

            currtime+=processingtime;
            result.push_back(orignalindex);

        }return result;
        
    }
};