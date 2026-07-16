/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxx = INT_MIN; // Start with the lowest possible number
        helper(root, maxx);
        return maxx;
    }

private:
    int helper(TreeNode* node, int& maxx) {
        // Base Case: An empty node contributes 0 to a path
        if (!node) return 0;

        // Step 1: Traverse left and right. 
        // We use max(0, ...) to completely ignore negative branches!
        int leftSum = max(0, helper(node->left, maxx));
        int rightSum = max(0, helper(node->right, maxx));

        // Step 2: Job 1 - Update the global record (The "V" shape)
        // Can we make a record-breaking path by connecting left + node + right?
        maxx = max(maxx, node->val + leftSum + rightSum);

        // Step 3: Job 2 - Return the best straight line up to the parent
        // The parent can only connect to ONE branch through us.
        return node->val + max(leftSum, rightSum);
    }
};