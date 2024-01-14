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
    int i = 0;
    TreeNode* createBST(vector<int>& preorder, int upBound) {
        if (i < preorder.size() && preorder[i] < upBound) {
            TreeNode* root = new TreeNode(preorder[i]);
            i++;
            // connect left and right subtrees to root
            root->left = createBST(preorder, root->val);
            root->right = createBST(preorder, upBound);
            return root;
        }
        return nullptr;                
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int upBound = INT_MAX;
        return createBST(preorder, upBound);
    }
};