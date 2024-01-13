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
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Inorder Traversal
        vector<int> ans;
        // O(1) space complexity
        TreeNode* cur = root;
        while(cur != nullptr) {
            // check if there is a left subtree
            if (!cur->left) {
                // no left subtree, so add cur to ans and move to right subtree
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else {
                // go to the right most element of left subtree and connect
                TreeNode* next = cur->left;
                while(next->right && next->right != cur) {
                    // we check second condition because there can already be a connection
                    next = next->right;
                }
                // create the connection if it is not there
                // if already conenction, then break connection -> means left subtree is done
                // so add cur to the ans
                if (next->right == cur) {
                    // already a connection, so break it
                    next->right = nullptr;
                    ans.push_back(cur->val);
                    cur = cur->right;
                } else {
                    // create the connection and traverse to left subtree
                    next->right = cur;
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
    
    vector<int> inorderTraversalIterative(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        vector<int> ans;
        if (!root) return ans;
        
        while (true) {
            // left -> root -> right
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } 
            else {
                if (stk.empty()) break;
                // no more left leaf -> print root
                cur = stk.top(); stk.pop();
                ans.push_back(cur->val);
                cur = cur -> right;
            }
        }
        return ans;
    }
};