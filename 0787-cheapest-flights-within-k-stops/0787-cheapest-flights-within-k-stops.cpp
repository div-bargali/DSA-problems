class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int e = flights.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i= 0; i < e; i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> prices(n, INT_MAX); // stores min price b/w src and dst with k stops
        prices[src] = 0;
        queue<pair<int, int>> q;
        q.push({0, src}); // {price, city}
        int level = 0;
        
        while(level <= k && !q.empty()) {
            int s = q.size();
            for (int j = 0; j < s; j++) {
                auto top = q.front(); q.pop();
                int price = top.first;
                int city = top.second;
    
                // explore adjacent nodes
                for (auto u: adj[city]) {
                    int fPrice = u.second;
                    int c = u.first;
                    if (fPrice + price < prices[c]) {
                        // update the min price and explore add to pq
                        prices[c] = fPrice + price;
                        q.push({prices[c], c});
                    }
                }
            }
            level++;
        }
        if (prices[dst] == INT_MAX) return -1;
        return prices[dst];
    }
};