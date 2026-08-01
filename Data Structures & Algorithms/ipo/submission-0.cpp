class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> arr;
        for(int i=0;i<profits.size();i++){
            arr[i].first=capital[i];
            arr[i].second=profits[i];
        }
        sort(arr.begin(),arr.end());
        priority_queue<int>pq;
        while(k--){
            int index=0;

            while(index>n){
                if(arr[index].first>w){
                    break;
                }
                    pq.push(arr[index].second);
                    index++;
                
            }

            w+=pq.top();
            pq.top();

        }return w;
    }
};