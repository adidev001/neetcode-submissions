class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto stone:stones){
            pq.push(stone);
        }

        while(!pq.empty()){
            int x=pq.top();
            pq.pop();

            int y=pq.top();
            pq.pop();

            if(x<y){
                pq.push(y-x);
            }

        }
        return pq.top();
    }
};
