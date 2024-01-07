class DisjointSet {
private:
	vector<int> size, parent;
public:
	DisjointSet(int n) {
		size.resize(n, 1);
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int findParent(int vertex) {
		// returns the ultimate parent of a vertex
		// here we are also using path compression
		if (parent[vertex] == vertex) 
			return vertex;
		// assigning the ultimate parent's value to the vertex's parent
		return parent[vertex] = findParent(parent[vertex]);
	}

	void unionBySize(int u, int v) {
		int ulP_u = findParent(u);
		int ulP_v = findParent(v);
		if (ulP_u == ulP_v) return; // do nothing

		if (size[ulP_u] < size[ulP_v]) {
			// connect smaller to larger
			parent[ulP_u] = ulP_v;
			size[ulP_v] += size[ulP_u];
		} else {
			parent[ulP_v] = ulP_u;
			size[ulP_u] += size[ulP_v];
		}
	}
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        DisjointSet ds(n);
        for (int i = 0; i < connections.size(); i++) {
            ds.unionBySize(connections[i][0], connections[i][1]);
        }
        // find no. of vertices whose ultimate parents are they themselves -> disconnected
        // components count
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i)
                cnt++;
        }
        return cnt - 1;
    }
};