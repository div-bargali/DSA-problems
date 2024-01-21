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
    int findHeightnDia(TreeNode* root, int &dia) {
        int leftH = 0, rightH = 0;
        if(root->left) leftH = findHeightnDia(root->left, dia);
        if (root->right) rightH = findHeightnDia(root->right, dia);
        
        // diameter at any node = left subtree's height + right subtree's height
        dia = max(dia, leftH + rightH);
        return 1 + max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int dia = 0;
        int treeH = findHeightnDia(root, dia);
        return dia;
    }
};