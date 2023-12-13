class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // base case 
        for (int i = 0; i <= n; i++) dp[i][0] = 0; // if s1's len is 0, then lcs is 0
        for (int j = 0; j <= m; j++) dp[0][j] = 0; // if s2's len is 0, then lcs is 0

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // now that lcs is created we can find length of the shortest common supersequenc
        int lenSCS = n + m - dp[n][m];
        string SCS = "";
        for (int i = 0; i < lenSCS; i++) SCS += "?";
        lenSCS--;
        // now we will iterate LCS table and create SCS in reverse order
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                // since both are same, we take only once
                SCS[lenSCS] = str1[i-1]; 
                lenSCS--; i--; j--;
            }
            else if (dp[i-1][j] >= dp[i][j-1]) {
                // since dp(i-1, j) is greater or equal, we move to dp(i-1, j)
                // discarding dp(i, j-1) -> so we will take the character str1[i-1]
                SCS[lenSCS] = str1[i-1];
                i--; lenSCS--;
            }
            else {
                // else we discard dp(i-1, j) -> so we take str1[i-1]
                SCS[lenSCS] = str2[j-1];
                j--; lenSCS--;
            }
        }
        while (i > 0) {
            SCS[lenSCS] = str1[i-1]; lenSCS--; i--;
        }
        while (j > 0) {
            SCS[lenSCS] = str2[j-1]; lenSCS--; j--;
        }

        return SCS;
    }
};