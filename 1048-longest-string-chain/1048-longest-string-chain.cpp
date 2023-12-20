class Solution {
public:
    static bool comp(string &s1, string &s2) {
        if (s1.length() < s2.length()) return true;
        return false;
    }
    bool isPredecessor(string &s1, string &s2) {
        int n = s2.length();
        int i = 0, j = 0;
        while(j < n && i < n-1) {
            if(s1[i] == s2[j]) {
                i++; j++;
            } else {
                j++;
            }
        }
        return (i == n-1 && (j == n || j == n-1));
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        
        // now logic is same as LIS
        vector<int> dp(n+1, 1);
        int ans = 1;
        // base case -> one word can be selected -> so min ans = 1
        
        for(int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (words[prev].length() + 1 == words[i].length() &&
                   isPredecessor(words[prev], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[prev]); // take or not take
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};