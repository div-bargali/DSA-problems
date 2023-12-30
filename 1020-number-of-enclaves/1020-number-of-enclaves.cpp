class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || 
           grid[i][j] == 0) return;
        
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
           
            dfs(x, y, grid, vis);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        // mark all 1's connected to boundary as visited
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, grid, vis);
            }
            if (grid[i][m-1] == 1 && !vis[i][m-1]) {
                dfs(i, m-1, grid, vis);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, grid, vis);
            }
            if (grid[n-1][j] == 1 && !vis[n-1][j]) {
                dfs(n-1, j, grid, vis);
            }
        }
        int ans = 0;
        // count all 1's that are not in boundary and not visited yet
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};