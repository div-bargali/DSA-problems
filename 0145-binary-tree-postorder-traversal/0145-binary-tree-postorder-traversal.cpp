class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> stk;
        stk.push(cur);
        int prev = -1;
        
        while(!stk.empty()) {
            cur = stk.top();

            if ((!cur->left && !cur->right) || 
                ((cur->left && prev == cur->left->val) || 
                 (cur->right && prev == cur->right->val))) 
            {
                // If the current node is a leaf or its children have been processed
                ans.push_back(cur->val);
                stk.pop();
                prev = cur->val;
            } else {
                if (cur->right) stk.push(cur->right);
                if (cur->left) stk.push(cur->left);
            }
        }
        return ans;
    }
};
