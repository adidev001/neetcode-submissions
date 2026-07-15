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
       
    return helper(root,INT_MIN,INT_MAX);


    }

    bool helper(TreeNode* rooot,int min,int max){
         if(!rooot){
            return true;
         }
        if(rooot->val <=min && rooot->val >=max){
        
        return false;

        }

        return helper(rooot->left,min,rooot->val) && helper(rooot->right,rooot->val,max);
    }
};
