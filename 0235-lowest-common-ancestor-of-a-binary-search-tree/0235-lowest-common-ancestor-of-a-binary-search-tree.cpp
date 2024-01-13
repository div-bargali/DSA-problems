/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (cur->val > p->val && cur->val > q->val) {
                // both on left
                cur = cur->left;
            } 
            else if (cur->val < p->val && cur->val < q->val) {
                // both on right
                cur = cur->right;
            }
            else {
                // since both are neither on left or right, cur should be LCA
                return cur;
            }
        }
    }
};