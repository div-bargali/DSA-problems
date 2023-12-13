class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s, s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s1.length(), m = s2.length();
        // tabulation
        // we will shift index by to handle the case when i1 < 0 -> i1 == -1 or i2 < 0 -> i2 == -1
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // base case -> when i1 == -1 || i2 == -1 -> shift index to right
        for (int i = 0 ; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};