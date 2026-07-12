class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1. Fix the base case: Empty trees ARE identical
        if (!p && !q) return true;
        
        // 2. Prevent the crash: If one is null but the other isn't, they don't match.
        // We MUST do this before checking p->val or q->val
        if (!p || !q) return false;
        
        bool flag = false;
        
        // 3. Your core logic: Only check further if the current values match
        if (p->val == q->val) {
            
            // 4. Capture the answers from the left and right sides
            bool leftMatch = isSameTree(p->left, q->left);
            bool rightMatch = isSameTree(p->right, q->right);
            
            // 5. Only set flag to true if BOTH sides matched perfectly
            if (leftMatch && rightMatch) {
                flag = true;
            }
        }
        
        return flag;
    }
};