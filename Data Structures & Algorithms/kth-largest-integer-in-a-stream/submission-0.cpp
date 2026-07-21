class KthLargest {
    priority_queue<int ,vector<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<k;i++){
            pq.push(nums[i])
        }

        int max= pq.top();
    }
    
    int add(int val) {
        pq.pop();
        pq.push(val);
        return pq.top();
    
    }
};
