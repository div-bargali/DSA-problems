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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr, *first = nullptr, *second = nullptr;
        TreeNode* cur = root;
        while(cur) {
            if (!cur->left) {
                // at the root, left subtree done
                if (prev != nullptr) {
                    if (cur->val < prev->val) {
                        // violation of BST property, store prev and cur
                        if (second == nullptr) {
                            // first violation
                            // both nodes are potential candidate
                            first = prev;
                            second = cur;
                        } else {
                            // second violation
                            // only cur is potential candidate, because prev followed
                            // the property in the last loop
                            second = cur;
                        }
                    }
                }
                prev = cur;
                cur = cur->right;
            }
            else {
                TreeNode* next = cur->left;
                while(next->right && next->right != cur) {
                    next = next->right;
                }
                if (next->right == cur) {
                     if (prev != nullptr) {
                        if (cur->val < prev->val) {
                            if (second == nullptr) {
                                first = prev;
                                second = cur;
                            } else {
                                second = cur;
                            }
                        }
                    }
                    prev = cur;
                    next->right = nullptr;
                    cur = cur->right;
                } else {
                    next->right = cur;
                    cur = cur->left;
                }
            }
        }
        // swap the nodes
        int temp = first->val;
        first->val = second->val; second->val = temp;
    }
};