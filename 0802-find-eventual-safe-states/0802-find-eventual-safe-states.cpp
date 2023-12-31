class Solution {
public:
    void dfs(int u, vector<bool> &vis, vector<bool> &isSafe, vector<int> &ans,
             vector<vector<int>> &graph) {
        vis[u] = true;
        bool flag = true;
        for (auto v: graph[u]) {
            if (!vis[v]) {
                dfs(v, vis, isSafe, ans, graph);
            }
            flag = flag & isSafe[v];
        }
        if (flag == true) {
            isSafe[u] = true;
            ans.push_back(u);
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<bool> vis(n, false);
        vector<bool> isSafe(n, false);
        vector<int> ans;
        
        for (int i = 0; i < n; i++){
            outdegree[i] = graph[i].size();
        }
        // all terminal nodes are safe
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) isSafe[i] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]){
                dfs(i, vis, isSafe, ans, graph);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};