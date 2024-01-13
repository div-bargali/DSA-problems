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
    bool isValidBST(TreeNode* root) {
        // morris traversal with keeping track of lastVisited 
        long long lastValue = LLONG_MIN;
        TreeNode* cur = root;
        bool flag = true;
        while(cur) {
            if (!cur->left) {
                if (lastValue >= cur->val) flag = false;
                lastValue = cur->val;
                cur = cur->right;
            }
            else {
                TreeNode* next = cur->left;
                while(next->right && next->right != cur) {
                    next = next->right;
                }
                if (next->right == cur) {
                    next->right = nullptr;
                    if (lastValue >= cur->val) flag = false;
                    lastValue = cur->val; // visiting root
                    cur = cur->right;
                } else {
                    next->right = cur;
                    cur = cur->left;
                }
            }
        }
        return flag;
    }
};