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
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        if (!root) return;
        stk.push(root);
        TreeNode* prev = nullptr;
        while(!stk.empty()) {
            TreeNode* cur = stk.top(); stk.pop();
            if (prev != nullptr) {
                prev->left = nullptr;
                prev->right = cur;
            }
            prev = cur;
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
        }
    }
};