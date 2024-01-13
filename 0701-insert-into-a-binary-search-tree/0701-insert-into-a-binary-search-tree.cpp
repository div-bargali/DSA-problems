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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* add = new TreeNode(val); 
        if (!root) return add;
        while(true) {
            if (cur->val > val) {
                // go left
                if (!cur->left) {
                    // since no left -> means cur is leaf node, add val to right
                    cur->left = add; break;
                } else {
                    cur = cur->left;
                }
            } else {
                // go right
                if (!cur->right) {
                    cur->right = add; break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};