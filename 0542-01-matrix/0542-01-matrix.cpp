class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // ans will act as visted array too
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        // we will start bfs from all the cells which are zero
        // at each level we will update the ans for all cells that are 1 and we reached 
        // at that level
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int level = 1;
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};
        while (!q.empty()) {
            int N = q.size();
            for (int z = 0; z < N; z++) {
                pair<int, int> cord = q.front(); q.pop();
                int x = cord.first;
                int y = cord.second;
                
                for (int i = 0; i < 4; i++) {
                    int X = x + dx[i];
                    int Y = y + dy[i];
                    if (X >= 0 && X < m && Y >= 0 && Y < n && mat[X][Y] == 1 
                    && ans[X][Y] == 0) {
                        ans[X][Y] = level;
                        q.push({X, Y});
                    }
                }
            }
            level++;          
        }
        return ans;
    }
};