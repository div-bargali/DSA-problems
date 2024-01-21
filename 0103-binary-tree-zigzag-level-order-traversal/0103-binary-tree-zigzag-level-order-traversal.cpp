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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        TreeNode* cur;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        vector<vector<int>> ans;
        while(!q.empty()){
            int  size = q.size();
            list<int> order;
            for (int i = 0; i < size; i++){
                cur = q.front(); q.pop();
                if (level % 2){
                    // order is 1, 2, 3
                    order.push_back(cur->val);
                } else {
                    // order is 3, 2, 1
                    order.push_front(cur->val);
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            level++;
            ans.push_back({order.begin(), order.end()});
        }
        return ans;
    }
};