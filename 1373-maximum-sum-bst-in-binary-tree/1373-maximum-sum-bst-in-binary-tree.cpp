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
    int ans = 0;
    
    vector<int> checkBST(TreeNode* root) {
        if (!root) {
            // {isBST, keySum, largestVal, smallestVal}
            return {1, 0, INT_MIN, INT_MAX}; // leaf node called this
        }
        auto l = checkBST(root->left);
        auto r = checkBST(root->right);
        
        if (l[0] && r[0]) {
            if (root->val > l[2] && root->val < r[3]) {
                // valid BST
                ans = max(ans, l[1] + r[1] + root->val);
                int largestVal = max(root->val, max(l[2], r[2]));
                int smallestVal = min(root->val, min(l[3], r[3]));
                return {1, l[1] + r[1] + root->val, largestVal, smallestVal};
            }
        } 
        return {0, 0, INT_MIN, INT_MAX};
       
    }
    int maxSumBST(TreeNode* root) {
        auto res = checkBST(root);
        return ans;
    }
};