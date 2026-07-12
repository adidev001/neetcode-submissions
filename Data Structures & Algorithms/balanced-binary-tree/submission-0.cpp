class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int res = checkheight(root);
        if(res == -1){
            return false;
        }else{
            return true;
        }
    }
private:
    int checkheight(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = checkheight(root->left);
        int right = checkheight(root->right);
        if(left == -1) return -1;
        if(right == -1) return -1;
        if(abs(left - right) > 1){
            return -1;
        }
        return 1 + max(left,right);
    }
};