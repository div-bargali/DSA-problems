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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        int n = accounts.size();
        DisjointSet ds(n);
        // make a disjoinSet of all accounts
        for (int i = 0; i < accounts.size(); i++) {
            // we will map index to name 
            for (int j = 1; j < accounts[i].size(); j++) {
                // put email in map, if it does not exist
                string email = accounts[i][j];
                if (mp.find(email) == mp.end()) {
                    mp[email] = i;
                } else {
                    // since email already exist, means it was present for another 
                    // person before, so connect the 2 people/vertex
                    ds.unionBySize(i, mp[email]);
                }
            }
        }
        // now map will have only unique emails present mapped to their immediate parent
        // map all the emails to the ultimateParents
        vector<string> mergedMail[n];
        for (auto it : mp) {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};