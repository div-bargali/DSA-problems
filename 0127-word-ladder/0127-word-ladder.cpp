class Solution {
public:
    // TC - O(N+E)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<string> q;
        q.push(beginWord);
        
        // edge case -> when endWord not in wordList
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        // maintain a not visited set
        unordered_set<string> notVis(wordList.begin(), wordList.end());
        notVis.erase(beginWord); // same as marking the word visted
        
        int len = 1;
         while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string cur = q.front(); q.pop();
                if(cur == endWord){
                    return len;
                }
                string tmp = cur;
                for(int i = 0; i < cur.length(); i++){
                    char c = cur[i];
                    // vary cur's letters one by one
                    for(int j = 0; j < 26; j++){
                        cur[i] = 'a' + j;
                        if(cur == tmp) continue;
                        if(notVis.find(cur) != notVis.end()){
                            // cur is not visited
                            notVis.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[i] = c;
                }
            }
            len++;
        }
        return 0;
    }
    
    bool isTransformable(string &a, string &b) {
        int cnt = 0;
        int n = a.length(), m = b.length();
        if (n != m) return false;
        
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) cnt++;
        }
        return (cnt == 1);
        
    }
    // TC - O(N*N) + O(N+E)
    int ladderLengthUnpotimized(string beginWord, string endWord, vector<string>& wordList) {
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