class Solution {
public:
    bool dfs(int v, int c, vector<bool> &vis, vector<int> &color, vector<vector<int>> &graph) {
        vis[v] = true;
        color[v] = c;
        
        // First, check if any adjacent node has the same color
        for (auto u : graph[v]) {
            if (color[u] == c) return false;
        }
        
        // Then, recursively explore unvisited adjacent nodes
        for (auto u : graph[v]) {
            if (!vis[u]) {
                int C = c == 0 ? 1 : 0;
                if (!dfs(u, C, vis, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // Adjacent nodes will not have the same color.
        // color[i] = 0/1
        vector<int> color(n, -1); 
        vector<bool> vis(n, false);
        
        // Start DFS from each unvisited node
        for (int i = 0; i < n; ++i) {
            if (!vis[i] && !dfs(i, 0, vis, color, graph)) {
                return false;
            }
        }
        
        return true;
    }
};
