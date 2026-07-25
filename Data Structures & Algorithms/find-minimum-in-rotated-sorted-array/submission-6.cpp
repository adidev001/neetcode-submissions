class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        // Loop runs until the two pointers converge on the exact minimum
        while (l < r) {
            int mid = l + (r - l) / 2; 

            if (nums[mid] > nums[r]) {
                // Scenario A: The minimum is strictly in the right half
                l = mid + 1;
            } else {
                // Scenario B: The minimum is at 'mid' or in the left half
                r = mid;
            }
        }

        // Once l == r, we've found our minimum
        return nums[l];
    }
};