class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
      // use kahn's algo for topo sort can keep track of 
      // nodes with indegree 0. At the end of BFS all nodes should 
      // have indegree 0, if graph is acyclic
      vector<vector<int>> adj(n);
      vector<int> indeg(n, 0);
      int e = edges.size();
      vector<int> ans;

      for (int i = 0; i < e; i++) {
          adj[edges[i][1]].push_back(edges[i][0]);
      }

      // compute indegrees
      for (int i = 0; i < n; i++) {
          for (auto u: adj[i]) {
              indeg[u]++;
          }
      }

      // add all indegree 0 vertices to the queue
      queue<int> q;
      for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
      }
      int cnt = 0;
      // perform bfs
      while(!q.empty()) {
          int node = q.front(); q.pop();
          //we add node only when indegree is 0, so if it is in the queue
          // it's indegree was 0
          cnt++; 
          ans.push_back(node);
          // remove all the edges of this node to it's adjacent nodes
          for (auto u: adj[node]) {
              // decrease indegree of u by 1, as we removed the edge
              indeg[u]--;
              if (indeg[u] == 0)
                  q.push(u);
          }

      }
      if (cnt != n) return {};
      return ans;
    }
};