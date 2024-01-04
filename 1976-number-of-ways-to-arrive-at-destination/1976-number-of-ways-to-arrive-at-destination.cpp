class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<pair<long long, long long>> ways(n, {LLONG_MAX, 0});
        vector<vector<pair<int, int>>> adj(n);
        
        for (int i = 0; i < roads.size(); i++) {
            auto it = roads[i];
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        ways[0] = {0, 1};
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // time, node
        
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            long long time = top.first;
            int city = top.second;
            
            for (auto node: adj[city]) {
                int t = node.second;
                int c = node.first;
                
                if (time + t < ways[c].first) {
                    ways[c].first = time + t;
                    ways[c].second = ways[city].second % MOD; 
                    pq.push({time + t, c});
                }
                else if (time + t == ways[c].first) {
                    ways[c].second = (ways[c].second + ways[city].second) % MOD;
                }
            }
        }
        
        if (ways[n-1].first == LLONG_MAX) return 0;
        return ways[n-1].second;
    }
};
