class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val); 
        inorder(root->left, result);   // Left
          // Root
        inorder(root->right, result);  // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        inorder(root, result);

        return result;
    }
};