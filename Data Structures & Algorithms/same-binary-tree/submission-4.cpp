class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1. Fix the base case: Empty trees ARE identical
        if (!p && !q) return true;
        

        if (!p || !q) return false;
        
        bool flag = false;
        
        if (p->val == q->val) {
            
            // 4. Capture the answers from the left and right sides
            bool leftMatch = isSameTree(p->left, q->left);
            bool rightMatch = isSameTree(p->right, q->right);
            
            if (leftMatch && rightMatch) {
                flag = true;
            }
        }
        
        return flag;
    }
};