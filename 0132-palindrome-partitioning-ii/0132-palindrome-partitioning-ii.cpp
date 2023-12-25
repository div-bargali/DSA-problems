class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    int solve(int i, int n, string &s, vector<int> &dp) {
        // base case
        if (i == n) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        int minCuts = INT_MAX;
        for (int k = i; k < n; k++) {
            if (isPalindrome(s, i, k)) {
                minCuts =  min(minCuts, 1 + solve(k+1, n, s, dp));  
            }
        }
        return dp[i] = minCuts;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, INT_MAX);
        // recursion + memo
        // return solve(0, n, s, dp) - 1; // since we are counting 1 extra partion in the end
        // tabulation 
        // base case
        
        // Optimization to reduce time complexity to O(N*N)
        vector<vector<bool>> palindrome(n+1, vector<bool>(n+1, false));
            // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            palindrome[i][i] = true;
        }

        // Check substrings of length 2 or more
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Check if the substring (i, j) is a palindrome
                palindrome[i][j] = (s[i] == s[j]) && (len == 2 || palindrome[i + 1][j - 1]);
            }
        }
        
        dp[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            int minCuts = INT_MAX;
            for (int k = n-1; k >= i; k--) {
                if(palindrome[i][k]) {
                    minCuts = min(minCuts, 1 + dp[k+1]);
                }
            }
            dp[i] = minCuts;
        }
        return dp[0] - 1;
    }
};