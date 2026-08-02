#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total_sum = 0;
        
        int cur_max = 0;
        int global_max = nums[0];
        
        int cur_min = 0;
        int global_min = nums[0];
        
        for (int num : nums) {
            total_sum += num;
            
            // --- Greedy Max Subarray ---
            cur_max += num;
            global_max = std::max(global_max, cur_max);
            // Greedy reset: If running sum is negative, throw it away
            if (cur_max < 0) {
                cur_max = 0;
            }
            
            // --- Greedy Min Subarray ---
            cur_min += num;
            global_min = std::min(global_min, cur_min);
            // Greedy reset: If running sum is positive, throw it away
            if (cur_min > 0) {
                cur_min = 0;
            }
        }
        
        // Edge Case: If all numbers are negative, global_max is negative
        if (global_max < 0) {
            return global_max;
        }
        
        return std::max(global_max, total_sum - global_min);
    }
};