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
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int> &valIdMp) {
        // base case 
        if (preStart > preEnd || inStart > inEnd) 
            return NULL;
        // preorder is root -> left -> right, so preorder[0] is root of whole tree
        TreeNode* root = new TreeNode(preorder[preStart]);
        // find index of root is the inorder
        int rootInIdx = valIdMp[root->val];
        // preorder is root -> left -> right, so if left subtree has 3 nodes, then 
        // next 3 nodes of preorder will be of the left subtree, rest will be of right subtre
        int leftNodes = rootInIdx - inStart;
        
        // inorder is left -> root -> right, so everything on left of root's idx is left subtree and everything on right is right subtree
        // attach left subtree to root
        root->left = helper(preorder, inorder, preStart+1, preStart+leftNodes, inStart, rootInIdx-1, valIdMp);
        // attach right subtree to root
        root->right = helper(preorder, inorder, preStart+leftNodes+1, preEnd, rootInIdx+1, inEnd, valIdMp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> valIdxMp; // maps node value to index in the inorder traversal
        for (int i = 0; i < n; i++) {
            valIdxMp[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, n-1, 0, n-1, valIdxMp);
    }
};