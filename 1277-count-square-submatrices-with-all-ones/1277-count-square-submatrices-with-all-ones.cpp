class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // dp[i][j] will store the count of squares whose bottom-right corner is (i, j)
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case 
        for (int i = 0; i < m; i++) dp[i][0] = matrix[i][0];
        for (int j = 0; j < n; j++) dp[0][j] = matrix[0][j]; 
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // check the top, left and diagonal element of dp
                // the minimum value will be the the indicator that if a square can be made
                // of these 4 values & the value itself will give the indicator of the count of square
                if (matrix[i][j] == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                   min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
            }
        }
        int sqCnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sqCnt += dp[i][j];
            }
        }

        return sqCnt;
    }
};