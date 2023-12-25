class Solution {
public:
    int solve(int i, int j, int k, vector<int> &arr, vector<vector<int>> &dp) {
        // base case 
        if (i > j) return 0; // maxSum will be 0
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxSum = -1;
        for (int x = i; x < i+k && x <= j; x++) {
            // partition the array at x
            // for left subarray maxSum = max(arr[i ... x]) * x-i+1
            // for right partition recursively find the ans
            maxSum = max(maxSum, *max_element(arr.begin()+i, arr.begin()+x+1)*(x-i+1) + 
                            solve(x+1, j, k, arr, dp));
        }
        return dp[i][j] = maxSum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, k, arr, dp);
    }
};