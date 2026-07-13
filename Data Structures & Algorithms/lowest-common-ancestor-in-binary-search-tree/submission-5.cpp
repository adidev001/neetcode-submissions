class Solution {
    TreeNode* ans = nullptr;

public:
    // This is the main function LeetCode calls (it MUST return a TreeNode*)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root, p, q); // Call your helper function
        return ans;      // Return the global answer
    }

    // This is the function from your screenshot (it returns an int)
    int fun(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr) return 0;

        int left = fun(node->left, p, q);
        int right = fun(node->right, p, q);
        
        int self = 0;
        if (node == p || node == q) {
            self = 1;
        }

        int total = left + self + right;
        
        if (total == 2 && ans == nullptr) {
            ans = node;
        }

        return total; 
    }
};