class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> time(n, vector<int>(n, INT_MAX));
        time[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;  // min heap
        pq.push({grid[0][0], {0, 0}}); // time to reach cell (0,0)
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        // DijKstra's
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            int t = top.first; // min time to reach from (0, 0) -> (i, j)
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if (x < n && y < n && x >= 0 && y >= 0) {
                    // time to reach from (0, 0) -> (x, y) will be grid[x][y]
                    int timeToReach = max(grid[x][y], t); 
                    if (timeToReach < time[x][y]) {
                        time[x][y] = timeToReach;
                        pq.push({time[x][y], {x, y}});
                    }
                }
            }
        }
        return time[n-1][n-1];
        
    }
};