class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp) {
        // base case 
        if (j < 0) return 1; // found 1 occurence of t in s
        if (i < 0) return 0; // exhausted s but could not find t
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) 
            return dp[i][j] = solve(s, t, i-1, j-1, dp) + solve(s, t, i-1, j, dp); // take OR not take
        else 
            return dp[i][j] = solve(s, t, i-1, j, dp); // not take if no match
    }
    
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, t, n-1, m-1, dp);
    }
};