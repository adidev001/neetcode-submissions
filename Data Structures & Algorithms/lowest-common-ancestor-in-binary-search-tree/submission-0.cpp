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
    TreeNode* ans=nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return 0;
        }

        int left=lowestCommonAncestor(root->left,  p,  q);
        int right=lowestCommonAncestor(root->right,  p,  q);
        int self=0;
        if(root->val==p || root->val==q){
            self=1;
        }
        int total =left+right+self;

        if(total==2 && ans=nullptr){
            ans=node;
        }

        return total;
    }
};
