class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        efforts[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        
        while(!pq.empty()) {
            int s = pq.size();
            for (int k = 0; k < s; k++) {
                auto top = pq.top(); pq.pop();
                int e = top.first;
                int i = top.second.first;
                int j = top.second.second;
                // explore adjacent nodes
                for (int l = 0; l < 4; l++) {
                    int x = i + dx[l];
                    int y = j + dy[l];
                    if (x >= 0 && y >= 0 && x < n && y < m) {
                        // check if effort required of path is less
                        int pathEfforts = max(e, abs(heights[i][j] - heights[x][y]));
                        if (pathEfforts < efforts[x][y]) {
                            // update the min efforts and explore add to pq
                            efforts[x][y] = pathEfforts;
                            pq.push({pathEfforts, {x, y}});
                        }
                    }
                }
            }
        }
        return efforts[n-1][m-1];
    }
};