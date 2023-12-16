class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
        // base case
        if (i < 0 && j < 0) return true;
        if (i >= 0 && j < 0) return false;
        // if s has no characters
        // there is one case when p can still match s
        // which is -> if p(0..j) is all  * -> "***..."
        if (i < 0 && j >= 0) {
            while(j >= 0 && p[j] == '*') j--;
            return (j < 0);
        } 
        if (dp[i][j] != -1) return dp[i][j];
            
        if (s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(s, p, i-1, j-1, dp);

        if (p[j] == '*') {
            // if p[j] == '*' then 
            // we can treat p[j] has empty and skip matching
            // or we can skip any # of characters from s(0..i) -> so do both
            bool noSkip = solve(s, p, i, j-1, dp); // treating p[j] as empty
            bool skip = solve(s, p, i-1, j, dp); // here we are not moving j -> because in next step we can again skip one more character from s
            // this is similar to doing a for loop for skipping characters from s
            return dp[i][j] = noSkip | skip;
        }
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, n-1, m-1, dp);
    }
};