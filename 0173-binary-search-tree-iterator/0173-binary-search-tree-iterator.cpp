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
class BSTIterator {
private:
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        int ans = -1;
        while(cur) {
            if (!cur->left) {
                // nothing on left means cur should be returned 
                ans = cur->val;
                cur = cur->right;
                break; // because next() will return only 1 node at a time
            }
            else {
                // create the conn b/w extreme right of left subtree and cur
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == cur) {
                    // conn already there, lefttree traveresed, next should return cur
                    ans = cur->val;
                    cur = cur->right;
                    break;
                }
                else {
                    // conn not there, so traverse left subtree 
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return cur != nullptr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */