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
    int kthSmallest(TreeNode* root, int k) {
        int result=-1;
        fun(root,k,result);
        return result;
    }

    void fun(TreeNode* root,int &k,int &result ){
        if(!root){
            return;
        }

        fun(root->left,k,result);
        k--;
        if(k==0){

            result=root->val;
            return;
        }

        if(k>0){
            fun(root->right,k,result);
            
        }

    }




};
