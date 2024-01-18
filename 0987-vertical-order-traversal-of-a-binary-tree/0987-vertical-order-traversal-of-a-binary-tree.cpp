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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // need to find diameter of tree first
        // then define a vector of vector of size dia
        // then do a top view of tree algo, for horizontal dist
        map<int, map<int, multiset<int>>> mp; 
        // maps horizDist -> level -> vector of values
        
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 1}}); // taking horiz dist of root as 0, and level = 1
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int horizDist = cur.second.first;
            int level = cur.second.second;
           
            mp[horizDist][level].insert(cur.first->val);
            
            if (cur.first->left)
                q.push({cur.first->left, {horizDist-1, level+1}});
            if (cur.first->right)
                q.push({cur.first->right, {horizDist+1, level+1}});
        }
        for (auto h: mp) {
            vector<int> nodes;
            for (auto l: h.second) {
                for (int e: l.second) 
                    nodes.push_back(e);
            }
            ans.push_back(nodes);
        }
        return ans;
    }
};