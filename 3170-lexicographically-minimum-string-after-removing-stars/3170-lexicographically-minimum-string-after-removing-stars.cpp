class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<bool> removed(n, false); // for marking index as removed
        vector<vector<int>> chars(26); // stores index of occurence of chars
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                // if smallest char is present
                removed[i] = true;
                for (int j = 0; j < 26; j++) {
                    if (chars[j].size() > 0) {
                        int idx = chars[j].back();
                        removed[idx] = true;
                        chars[j].pop_back();
                        break;
                    }
                }
            } else {
                chars[s[i] - 'a'].push_back(i);
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (!removed[i])
                ans += s[i];
        }
        return ans;
    }
};