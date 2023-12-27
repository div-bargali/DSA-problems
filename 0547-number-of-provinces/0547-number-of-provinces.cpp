class Solution {
public:
    void dfs(int v, int n, vector<bool> &vis, vector<vector<int>> &isConnected) {
        vis[v] = true;
        
        for (int i = 0; i < n; i++) {
            if (isConnected[i][v] == 1 && !vis[i]) dfs(i, n, vis, isConnected);
        }
        
        for (int j = 0; j < n; j++) {
            if (isConnected[v][j] == 1 && !vis[j]) dfs(j, n, vis, isConnected);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, n, vis, isConnected);
                ans++;
            }
        }
        return ans;
    }
};