class DisjointSet {
private:
    std::vector<int> parent, size;

public:
    DisjointSet(int n) : size(n, 1), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int vertex) {
        // using path compression
        if (parent[vertex] == vertex)
            return vertex;
        return parent[vertex] = findUParent(parent[vertex]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
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
};

class Solution {
public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        int n = stones.size();
        DisjointSet dsu(n);
        std::unordered_map<int, int> col;
        std::unordered_map<int, int> row;

        for (int i = 0; i < n; ++i) {
            int c = stones[i][0];
            int r = stones[i][1];
            if (col.find(c) == col.end())
                col.insert(std::make_pair(c, i));
            if (row.find(r) == row.end()) 
                row.insert(std::make_pair(r, i));
            dsu.unionBySize(i, row[r]); 
            dsu.unionBySize(i, col[c]);
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (dsu.findUParent(i) == i) {
                components++;
            }
        }

        return n - components;
    }
};
