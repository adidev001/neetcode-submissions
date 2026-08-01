class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int,int>> arr(n); 
        for(int i = 0; i < n; i++) {
            arr[i].first = capital[i];
            arr[i].second = profits[i];
        }
        
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        
        int index = 0; 
        
        while(k--) {
            while(index < n && arr[index].first <= w) {
                pq.push(arr[index].second);
                index++;
            }
            
            if(pq.empty()) {
                break; 
            }
            
            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};