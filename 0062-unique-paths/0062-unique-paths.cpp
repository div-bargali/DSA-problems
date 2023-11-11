class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if (i >= 0 && j >= 0 && i < m && j < n) return true;
        return false;
    }
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        if(i == 0 && j == 0) return 1;

        int left = 0, top = 0;
        if (isValid(i, j-1, m, n)) {
            left = solve(i, j-1, m, n, dp);    
        }

        if (isValid(i-1, j, m, n)) {
            top = solve(i-1, j, m, n, dp);
        }

        int sum = left + top;
        return dp[i][j] = sum;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, m, n, dp);
    }
};