class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 2 step approach -
        // 1. find the min len while keeping track of all words encountered in each level
        // 2. backtrack from the endWord to find all possible ways to reach beginWord
        // with minimun no. of transformations
        unordered_set<string> notVis(wordList.begin(), wordList.end());
        queue<string> q;
        unordered_map<string, int> mp;
        q.push(beginWord);
        notVis.erase(beginWord);
        mp[beginWord] = 1; // beginWord will be at level 1
        
        while(!q.empty()) {
            string word = q.front(); q.pop();
            int level = mp[word];
            if (word == endWord) break;
            
            string tmp = word;
            for (int i = 0; i < word.length(); i++){
                char c = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    if (word == tmp) continue;
                    if (notVis.find(word) != notVis.end()) {
                        mp[word] = level + 1;
                        notVis.erase(word);
                        q.push(word);
                    }
                }
                word[i] = c;
            }
        }
        
        // step 2 - backtrack the map using DFS
        // we start from endWord ans backtrack until we have found the beginWord
        vector<vector<string>> ans;
        vector<string> seq;
        seq.push_back(endWord);
        // check if we have endWord -> then backtrack
        if (mp.find(endWord) != mp.end()) {
            dfs(endWord, beginWord, mp, seq, ans);
        }
        // reverse all the sequence in ans
        for (auto &s: ans) reverse(s.begin(), s.end());
        return ans;
    }
    
    void dfs(string &word, string &beginWord, unordered_map<string, int> &mp, vector<string> &seq, vector<vector<string>> &ans) {
        if (word == beginWord) {
            ans.push_back(seq);
            return;
        }
        int level = mp[word];
        int n = word.length();
        
        string tmp = word;
        for (int i = 0; i < n; i++){
            char c = tmp[i];
            for (int j = 0; j < 26; j++) {
                tmp[i] = 'a' + j;
                if (tmp == word) continue;
                if (mp.find(tmp) != mp.end() && mp[tmp] == level - 1) {
                    // if the transformed word is just one level above current word's level then it is part of the sequence
                    seq.push_back(tmp);
                    dfs(tmp, beginWord, mp, seq, ans);
                    // backtrack - pop back to find other possibilities
                    seq.pop_back();
                } 
            }
            tmp[i] = c;
        }
    }
};