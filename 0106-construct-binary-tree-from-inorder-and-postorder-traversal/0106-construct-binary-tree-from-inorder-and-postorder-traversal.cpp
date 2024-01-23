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
    TreeNode* buildTreeHelper(int posStart, int posEnd, int inStart, int inEnd, vector<int> &postorder, vector<int> &inorder, unordered_map<int, int> &mp) {
        if (posStart > posEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[posEnd]);
        int inorderRtIdx = mp[root->val];
        
        // nodes left of root are left subtree nodes
        int nodesInLeft = inorderRtIdx - inStart;
        root->left = buildTreeHelper(posStart, posStart+nodesInLeft-1, inStart, inorderRtIdx-1, postorder, inorder, mp);
        
        root->right = buildTreeHelper(posStart+nodesInLeft, posEnd-1, inorderRtIdx+1, inEnd, postorder, inorder, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posStart = 0, inStart = 0, posEnd = postorder.size()-1, inEnd = inorder.size()-1;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return buildTreeHelper(posStart, posEnd, inStart, inEnd, postorder, inorder, mp);
    }
};