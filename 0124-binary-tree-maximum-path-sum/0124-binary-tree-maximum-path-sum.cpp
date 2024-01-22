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
    int mxPathSum(TreeNode* root, int &maxPathSum) {
        if (!root) return 0;
        
        // calculate max pathSum of left and right subtrees
        int leftPathSum = max(0, mxPathSum(root->left, maxPathSum));
        int rightPathSum = max(0, mxPathSum(root->right, maxPathSum));
        // pathSum with cur node as root        
        int curPathSum = root->val + leftPathSum + rightPathSum;
        maxPathSum = max(maxPathSum, curPathSum);
        // return the mx Path sum 
        return root->val + max(leftPathSum, rightPathSum); // take either left or right path
        
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int maxPath = mxPathSum(root, ans);
        return ans;
    }
};