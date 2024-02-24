class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1, pStart = 0; // start of the palindromic substring
        // BASE CASES
        // all substrings of length 1 will be palindromes
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        
        // checking for substrings of length 2
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                maxLen = 2;
                pStart = i-1;
                dp[i-1][i] = true;
            }
        }
        
        // for length 3 onwards, bottom-up DP
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i+1][j-1] == true) {
                    // substring s[i..j] is a palindrome
                    dp[i][j] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        pStart = i;
                    }
                }
            }
        }
        return s.substr(pStart, maxLen);
    }
};