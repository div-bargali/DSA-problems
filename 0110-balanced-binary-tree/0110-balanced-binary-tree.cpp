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
    pair<int, int> checkBalance(TreeNode* root) {
        // returns {height of subtree, 0/1 for if tree is balanced}
        if (!root) return {0, 1};
        
        auto lef = checkBalance(root->left);
        int leftH = lef.first;
        int leftBal = lef.second;
        
        auto rig = checkBalance(root->right);
        int rightH = rig.first;
        int rightBal = rig.second;
        
        if (abs(leftH - rightH) <= 1 && leftBal && rightBal) 
            return {1 + max(leftH, rightH), 1}; // subtree is balanced
        return {1 + max(leftH, rightH), 0}; // subtree is not balanced
    }
    int height(TreeNode* root) {
        int leftH = 0, rightH = 0;
        if (root->left) leftH = height(root->left);
        if (root->right) rightH = height(root->right);
        return max(leftH, rightH) + 1;
    }
    bool solve(TreeNode* root) {
        int leftH = 0, rightH = 0;
        if (!root) return true;
        if (root->left) leftH = height(root->left);
        if (root->right) rightH = height(root->right);
        if (abs(leftH - rightH) <= 1 && solve(root->left) && solve(root->right))
            return true;
        return false;
    }
    bool isBalanced(TreeNode* root) {
        // return solve(root); O(N^2) approach
        if (!root) return true;
        auto ans = checkBalance(root);
        return ans.second;
    }
};