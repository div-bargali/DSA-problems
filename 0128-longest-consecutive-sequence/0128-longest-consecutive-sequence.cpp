class DisjointSet {
public:
    unordered_map<int, int> parent, size;
    int maxLen = 1;
    DisjointSet (int n) {
        
    }
    int findUParent(int vertex) {
        // using path compression
        if (parent[vertex] == vertex) return vertex;
        return parent[vertex] = findUParent(parent[vertex]);
    }  
    void unionBySize(int u, int v) {
        // union will do a union of v to u always -> since v > u
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        else {
            // join smaller to larger
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        maxLen = max(maxLen, size[ulp_u]);
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        DisjointSet ds(n);
        for (int i = 0; i < n; i++) {
            ds.parent[nums[i]] = nums[i];
            ds.size[nums[i]] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (ds.parent.find(nums[i]+1) != ds.parent.end()) {
                // do a union
                ds.unionBySize(nums[i], nums[i]+1);
            }
            if (ds.parent.find(nums[i]-1) != ds.parent.end()) {
                // do a union
                ds.unionBySize(nums[i]-1, nums[i]);
            }
        }
        return ds.maxLen;
    }
};

