class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<array<long long,3>> main;
        long long index = 0;
        long long currtime = 0;
        
        for(auto a : tasks){
            main.push_back({a[0], a[1], index++});
        }
        
        sort(main.begin(), main.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> result;
        int n = main.size();
        
        int i = 0;
        while(i < n || !pq.empty()){
            
            // ISSUE 1 FIXED: Added `i < n` and changed `||` to `&&`.
            // Without `i < n`, `main[i][0]` causes a Segmentation Fault when i == n.
            // You only fast-forward time IF the queue is empty AND the next task hasn't arrived.
            if(pq.empty() && i < n && main[i][0] > currtime){
                currtime = main[i][0];
            }

            // ISSUE 2 FIXED: Changed `||` to `&&` and fixed typo `main[1]` to `main[i]`.
            // With `||`, the loop never stops if the right side is true, causing a crash.
            while(i < n && main[i][0] <= currtime){
                
                // ISSUE 3 FIXED: Changed to push processing time (index 1) and original index (index 2).
                // You were previously pushing enqueue time (index 0) and processing time (index 1).
                pq.push({main[i][1], main[i][2]}); 
                i++;
            }

            auto [processtime, orignalindex] = pq.top();
            pq.pop();

            currtime += processtime;
            result.push_back(orignalindex);
        }
        
        return result;
    }
};