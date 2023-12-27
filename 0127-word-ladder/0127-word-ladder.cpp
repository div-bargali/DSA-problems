class Solution {
public:
    bool isTransformable(string &a, string &b) {
        int cnt = 0;
        int n = a.length(), m = b.length();
        if (n != m) return false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) cnt++;
        }
        return (cnt == 1);
        
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        queue<int> q;
        
        // edge case -> when endWord not in wordList
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        // create adj list for BFS traversal
        // Create adj list for BFS traversal
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isTransformable(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        // we will do bfs by adding all transformations beginWord in the queue first
        for (int i = 0; i < n; i++) {
            if (isTransformable(wordList[i], beginWord)) {
                q.push(i); 
                vis[i] = true; 
            }
        }
        
        int len = 1; // first transformation already added in queue
        // edge case - when beginWord in wordList
        if (find(wordList.begin(), wordList.end(), beginWord) != wordList.end()) 
            len = 1;
        
        bool flag = false;
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int node = q.front(); q.pop();
                if (wordList[node] == endWord) {
                    flag = true;
                    return len+1;
                }
                for (auto e: adj[node]) {
                    if (!vis[e]) {
                        q.push(e);
                        vis[e] = true;
                    }
                }   
            }
            len++;
        }
        
        return flag ? len : 0;
        
    }
};