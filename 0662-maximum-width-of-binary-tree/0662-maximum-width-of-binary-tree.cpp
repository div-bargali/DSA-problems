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
    int widthOfBinaryTree(TreeNode* root) {
        // level order traversal with index
        // in a Binary tree, if node is at index i (0-based indexing)
        // left child will be at index - 2*i+1 and right child at index - 2*i+2
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0}); // 0 - based index
        int ans = INT_MIN;
        while(!q.empty()) {
            int s = q.size();
            int left, right;
            // if idx = 14 and left-most index at level is 7, then width would have been 8
            // if we make idx = 7 and left-most index as 0, then also width will be 8
            // so use leftMostIdx to shift all indices of the level to start from 0.
            int leftMostIdx = q.front().second;
            for (int i = 0; i < s; i++) {
                auto cur = q.front(); q.pop();
                int curIdx = cur.second - leftMostIdx; // prevents integer overflow
                if (i == 0) left = curIdx; // index of the cur node
                if (i == s-1) right = curIdx;
                if (cur.first->left)
                    q.push({cur.first->left, (long long)2 * curIdx + 1});
                if (cur.first->right)
                    q.push({cur.first->right, (long long)2 * curIdx + 2});
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};