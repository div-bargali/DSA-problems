class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i==0) dp[i][j] = matrix[i][j]; 
                else {
                    int left = INT_MAX, center = INT_MAX, right = INT_MAX;
                    if(j == 0) {
                        center = dp[i-1][j];
                        right = dp[i-1][j+1];
                    }
                    else if (j == n-1) {
                        left = dp[i-1][j-1];
                        center = dp[i-1][j];
                    }
                    else {
                        left = dp[i-1][j-1];
                        center = dp[i-1][j];
                        right = dp[i-1][j+1];
                    }
                    dp[i][j] = min(left, min(center, right)) + matrix[i][j];
                } 
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};