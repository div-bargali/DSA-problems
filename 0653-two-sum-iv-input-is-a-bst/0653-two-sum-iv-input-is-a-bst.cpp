class BSTIterator {
private:
    stack<TreeNode*> stk;
    bool isReverse;
    
    void pushAll(TreeNode* root) {
        while (root) {
            stk.push(root);
            if (isReverse == false) {
                // doing forward inorder -> 1 > 2 > 3
                // push all the left-most nodes from root to leaf into stack
                root = root->left;
            } else {
                // doing backward inorder -> 3 > 2 > 1
                // push all the right-most nodes from root to leaf into stack
                root = root->right;
            }
        }
    }
public:
    BSTIterator(TreeNode* root, bool reverse) {
        isReverse = reverse;
        pushAll(root); 
    }
    bool hasNext() {
        // if stack is not empty, we still have nodes remaining to be traversed
        return !stk.empty();
    }
    int next() {
        // first/next element will always be top of stack
        TreeNode* cur = stk.top(); stk.pop();
        if (isReverse == false) {
            pushAll(cur->right); // push all left-most nodes from cur->right
        } else {
            pushAll(cur->left); // push all right-most nodes from cur->left
        }
        return cur->val;
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        // l.next() gives next smallest element in BST
        BSTIterator l(root, false); 
        // r.next() gives next largest element in BST
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};