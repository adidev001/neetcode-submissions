class Solution {
    int count = 0; // Class-level variable
public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }

    void dfs(TreeNode* node, int maxSoFar) {
        if (!node) return;

        if (node->val >= maxSoFar) {
            count++;
            maxSoFar = node->val;
        }

        dfs(node->left, maxSoFar);
        dfs(node->right, maxSoFar);
    }
};