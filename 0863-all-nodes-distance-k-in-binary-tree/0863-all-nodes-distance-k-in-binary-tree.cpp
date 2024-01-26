class Solution {
public: 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        unordered_map<TreeNode*, TreeNode*> parent = buildGraph(root);
        unordered_map<TreeNode*, bool> vis;
        
        // once we have all neighbors of a node -> left, right and parent
        // do a simple BFS
        queue<TreeNode*> q;
        q.push(target);
        int dist = 0;
        vector<int> ans;
        
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front(); q.pop();
                vis[cur] = true;
                if (dist == k) {
                    // all nodes currently in queue are at distance k from target
                    ans.push_back(cur->val);
                } else {
                    if (parent[cur] && !vis[parent[cur]]) q.push(parent[cur]);
                    if (cur->left && !vis[cur->left]) q.push(cur->left);
                    if (cur->right && !vis[cur->right]) q.push(cur->right);
                }
            }
            dist++;
        }
        return ans;
    }
private:
     unordered_map<TreeNode*, TreeNode*> buildGraph(TreeNode* root) {
        // 2 ways to convert tree to a undirectional graph
        // 1. create an adjacency list (more-intuitive)
        // 2. keep a map of node's parent (better appraoch because, other neighbors are already stored in left and right pointers)
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return parent;
    }
};