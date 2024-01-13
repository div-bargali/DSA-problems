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
    int kthSmallest(TreeNode* root, int k) {
        // 1. use morris traversal with a count of all the visited root nodes
        // 2. when count reaches k, return that node's value as answer
        int cnt = 0, ans = 0;
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (!cur->left) {
                cnt++;
                if (cnt == k) ans = cur->val;
                cur = cur->right;
            } 
            else {
                TreeNode* next = cur->left;
                while(next->right && next->right != cur) {
                    next = next->right;
                }
                if (next->right == cur) {
                    next->right = nullptr; // sever the connection
                    cnt++; // since visiting root
                    if (cnt == k) ans = cur->val;
                    cur = cur->right;
                } else {
                     next->right = cur; // create connection to current root
                     cur = cur->left; // traverse left subtree
                }
            }
        }
        return ans;
    }
};