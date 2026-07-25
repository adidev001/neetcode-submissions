class Solution {
   public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int result = r;

        while (l <= r) {
            int guess = l + (r - l) / 2;
            if (itcan(nums, k, guess)) {
                result = guess;
                r = guess - 1;
            } else {
                l = guess + 1;
            }
        }
        return result;
    }

   private:
    bool itcan(vector<int>& nums, int k, int guess) {
        int curr = 0;
        int subarray = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (curr +nums[i] > guess) {
                subarray++;
                curr = nums[i];

            } else {
                curr += nums[i];
            }
        }
        if (subarray > k) {
            return false;
        } else {
            return true;
        }
    }
};