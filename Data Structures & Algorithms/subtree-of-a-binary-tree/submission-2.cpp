/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subroot) return true;
        if (!root) return false;
        if (same(root, subroot)) {
            return true;
        }
        return (isSubtree(root->left, subRoot->left) || isSubtree(root->right, subRoot->right));
    }

    bool same(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subroot) return true;
        if (!root || !subroot) return false;

        if (p && q && p->val == q->val) {
            return (same(root->left, subroot->left) || same(root->right, subroot->right))
        }
        return false;
    }
};
