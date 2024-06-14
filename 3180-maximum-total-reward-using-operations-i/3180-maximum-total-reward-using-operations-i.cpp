class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        int n = nums.size();
        int x = 4001; // max possible sum can be btw 1999 + 2000
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(n, vector<int>(x+1, 0));
        
        for (int j = 0; j < nums[n-1]; j++) dp[n-1][j] = nums[n-1];
        
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= x; j++) {
                if (nums[i] > j) {
                    dp[i][j] = max(nums[i] + dp[i+1][j + nums[i]],
                                  dp[i+1][j]);
                } else 
                    dp[i][j] = dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};