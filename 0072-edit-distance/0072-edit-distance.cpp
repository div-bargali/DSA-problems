class Solution {
public:
    int solve(string& s, string& t, int i, int j, vector<vector<int>> &dp) {
        // base case
        // 1. if t is empty -> delete all characters in s(0..i)
        if (j < 0) return i + 1;
        // 2. if s is empty -> insert all characters of t(0..j) into s
        if (i < 0) return j + 1;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) 
            return dp[i][j] = solve(s, t, i-1, j-1, dp);
        
            
        else 
            return dp[i][j] = 1 + min(min(solve(s, t, i-1, j-1, dp), // replace a character
                          solve(s, t, i, j-1, dp)), // insert a character
                            solve(s, t, i-1, j, dp)); // delete a character
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, n-1, m-1, dp);
    }
};