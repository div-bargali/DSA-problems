class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        // initialization
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i < edges.size(); i++) {
            auto e = edges[i];
            int u = e[0], v = e[1], wt = e[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        // floyd warshall algo
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int> nearby(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] > 0 && dist[i][j] <= distanceThreshold) {
                    nearby[i]++; 
                }
            }
        }
        int idx = 0, minVal = 1e8;
        for (int i = 0; i < n; i++) {
            if (nearby[i] <= minVal) {
                idx = i; minVal = nearby[i];
            }
        }
        return idx;
    }
};