class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet (int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUParent(int vertex) {
        // using path compression
        if (parent[vertex] == vertex) return vertex;
        return parent[vertex] = findUParent(parent[vertex]);
    }  
    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        else {
            if (size[ulp_u] < size[ulp_v]) {
                // join smaller to larger
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u]; 
            } else {
                // join smaller to larger
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    }
    int findSize(int v) {
        return size[v];
    }
    int maxSize() {
        return *max_element(size.begin(), size.end());
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        
        // Step 1. Create Disjoint Set of the graph and connect islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // do union with adjacent cells if they are 1 and not same parent
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k] + i;
                        int y = dy[k] + j;
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1) {
                            int c1 = i * n + j; // translate 2d co-ordinates into 1D
                            int c2 = x * n + y; 
                            if (ds.findUParent(c1) != ds.findUParent(c2)) {
                                ds.unionBySize(c1, c2);
                            }
                        }
                    }
                }
            }
        }
        int ans = ds.maxSize();
        // Step 2. flip 1 zero, and connect with adjacent and return max value in size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    // store ultimate parents of all adjacent cell in a set
                    // set because it elimates duplicates
                    unordered_set<int> ult_Ps;
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k] + i;
                        int y = dy[k] + j;
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1) {
                            // translate 2d co-ordinates into 1D
                            int c1 = x * n + y; 
                            ult_Ps.insert(ds.findUParent(c1));
                        }
                    }
                    int adjSize = 0;
                    for (auto e: ult_Ps) {
                        adjSize += ds.findSize(e);
                    }
                    adjSize++; // add 1 because the current cell will also be included
                    ans = max(ans, adjSize);
                }
            }
        }
        return ans;
    }
};