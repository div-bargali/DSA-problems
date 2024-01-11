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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        vector<int> ans;
        if (!root) return ans;
        
        while (true) {
            // left -> root -> right
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } 
            else {
                if (stk.empty()) break;
                // no more left leaf -> print root
                cur = stk.top(); stk.pop();
                ans.push_back(cur->val);
                cur = cur -> right;
            }
        }
        return ans;
    }
};