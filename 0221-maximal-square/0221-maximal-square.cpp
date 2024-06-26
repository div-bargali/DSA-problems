class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // dp[i][j] will store the length of side of a square, whose bottom right point is (i, j)
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            if (dp[i][0]) ans = 1;
        } 
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j] - '0';
            if (dp[0][j]) ans = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] - '0' == 1) {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + (matrix[i][j] - '0');
                    // min of the three because if any of the one is 0, then the square's side can only be 1
                    ans = max(ans, dp[i][j] * dp[i][j]);
                }
            }
        }
        return ans;
    }
};