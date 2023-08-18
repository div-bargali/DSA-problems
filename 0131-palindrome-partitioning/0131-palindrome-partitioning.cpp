class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i <= j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    void solve(string& s, int i, vector<string>& sub, vector<vector<string>>& ans) {
        if (i == s.length()) {
            ans.push_back(sub);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (isPalindrome(s, i, j)) {
                sub.push_back(s.substr(i, j - i + 1));
                solve(s, j + 1, sub, ans);
                sub.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> sub;
        vector<vector<string>> ans;
        solve(s, 0, sub, ans);
        return ans;
    }
};