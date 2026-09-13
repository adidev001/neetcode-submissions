class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % k != 0) {
            return false;
        }

        int target = totalSum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) {
            return false;
        }

        vector<int> subsetSum(k, 0);

        return backtrack(nums, 0, subsetSum, target);
    }

private:
    bool backtrack(
        vector<int>& nums,
        int index,
        vector<int>& subsetSum,
        int target
    ) {
        if (index == nums.size()) {
            return true;
        }

        int currentNumber = nums[index];

        for (int i = 0; i < subsetSum.size(); i++) {
            if (subsetSum[i] + currentNumber > target) {
                continue;
            }

            subsetSum[i] += currentNumber;

            if (backtrack(nums, index + 1, subsetSum, target)) {
                return true;
            }

            subsetSum[i] -= currentNumber;
            if (subsetSum[i] == 0) {
                break;
            }
        }

        return false;
    }
};