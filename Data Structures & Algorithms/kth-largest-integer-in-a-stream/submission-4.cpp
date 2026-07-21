class KthLargest {
    int K;
    priority_queue<int ,vector<int>,greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {

       pq.push(val);
       while(pq.size()<k){
        pq.pop();
       }
        return pq.top();
    
    }
};
