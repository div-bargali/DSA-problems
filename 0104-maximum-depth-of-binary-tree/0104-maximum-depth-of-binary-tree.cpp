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
    int height(TreeNode* root) {
        int leftH = 0, rightH = 0;
        if (root->left) leftH = height(root->left);
        if (root->right) rightH = height(root->right);
        return max(leftH, rightH) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return height(root);
    }
};