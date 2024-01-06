class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // shortest path single source -> Dijkstra's
        vector<int> dist(n, 1e8);
        vector<vector<pair<int, int>>> adj(n);
        for (auto e: times) {
            int u = e[0]-1, v = e[1]-1, wt = e[2];
            adj[u].push_back({v, wt});
        }
        dist[k-1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k-1});
        
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int u = top.second;
            int d = top.first;
            for (auto e: adj[u]) {
                int v = e.first;
                int wt = e.second;
                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                } 
            }
        }
       for (int i = 0; i < n; i++) {
            if (dist[i] == 1e8) {
                return -1; // Some vertices are unreachable
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};