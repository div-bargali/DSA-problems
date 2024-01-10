class Solution {
public:
    void dfs(int n, int time, int parent, vector<int> &tInsert, vector<bool> &vis, vector<int> &minTInsertAdj, vector<vector<int>> &adj, vector<vector<int>> &br) {
        vis[n] = true;
        tInsert[n] = time; 
        // min time of visit of all adj nodes is initially s ame
        minTInsertAdj[n] = time; 
        time++;
        for (auto u: adj[n]) {
            if (u == parent) continue; // nothing is done for parent
            if (!vis[u]) {
                // do dfs of adjacent
                dfs(u, time, n, tInsert, vis, minTInsertAdj, adj, br);
                minTInsertAdj[n] = min(minTInsertAdj[u], minTInsertAdj[n]);
                if (minTInsertAdj[u] > tInsert[n]) {
                    // this is a bridge
                    br.push_back({n, u});
                }
            } else {
                // since u is already visited, means it was in path of n before too
                // so removing edge will not affect the connection
                // just update
                minTInsertAdj[n] = min(minTInsertAdj[u], minTInsertAdj[n]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tInsert(n, 0);
        vector<bool> vis(n, false);
        vector<int> minTInsertAdj(n, 0); // stores min of time of insertion/visit of all adj nodes of a node n (except it's parents)
        vector<vector<int>> bridges;
        vector<vector<int>> adj(n);
        for (auto c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        dfs(0, 0, -1, tInsert, vis, minTInsertAdj, adj, bridges);
        return bridges;
    }
};