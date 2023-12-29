class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isSafe(int x, int y, int m, int n){
        if(x < m && y < n && x >= 0 && y >= 0) return true;
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), r, c, fresh = 0;
        
        queue<pair<int, int>> bfs;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) bfs.push(make_pair(i, j));
                if(grid[i][j] == 1) fresh++;
            }
        }
        int time = -1;
        
        while(!bfs.empty()){
            int s = bfs.size();
            for(int i = 0; i < s; i++){
                auto cur = bfs.front(); bfs.pop();
                r = cur.first, c = cur.second;
                for(int j = 0; j < 4; j++){
                    int x = r + dx[j];
                    int y = c + dy[j];
                    if(isSafe(x, y, m, n) && grid[x][y] == 1){
                        grid[x][y] = 2;
                        bfs.push(make_pair(x, y));
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh > 0 ? -1 : (time == -1) ? 0 : time;
    }
};