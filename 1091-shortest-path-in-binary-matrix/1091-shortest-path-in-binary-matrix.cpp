class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // edge case
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1;
        
        int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};        
        vector<vector<bool>> vis (n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        
        int dis = 1;
        while(!q.empty()) {
            int m = q.size();
            for (int l = 0; l < m; l++) {
               auto p = q.front(); q.pop();
                int i = p.first, j = p.second;
                if (i == n-1 && j == n-1) return dis;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !vis[x][y]){
                        q.push({x, y});
                        vis[x][y] = true;
                    }
                } 
            }
            dis++;
        }
        return -1;
     }
};