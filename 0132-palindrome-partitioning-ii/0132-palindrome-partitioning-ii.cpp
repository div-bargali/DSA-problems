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
        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1; // since we are counting 1 extra partion in the end
    }
};