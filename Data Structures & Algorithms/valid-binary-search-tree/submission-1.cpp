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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return 0;


        }
        bool flag=false;

        if(!isValidBST(root->left)&&!isValidBST(root->right)){
            return false;
        }

        if(root->val>root->left->val && root->val<root->right->val){
            flag=true;
        }else{
            flag=false;
            return false;
        }

        return true;

    


    }
};
