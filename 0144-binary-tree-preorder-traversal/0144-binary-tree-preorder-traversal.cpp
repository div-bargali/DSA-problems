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
    vector<int> preorderTraversal(TreeNode* root) {
        // root -> left -> right
        stack<TreeNode*> stk;
        vector<int> ans;
        if (!root) return ans;
        stk.push(root);
        
        while(!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            ans.push_back(cur->val);
            // insert right first since LIFO
            if (cur->right) 
                stk.push(cur->right);
            if (cur->left)
                stk.push(cur->left);
        }
        return ans;
    }
};