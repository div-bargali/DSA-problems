class Solution {
public:
    int solve(int ind, int prev, int n, vector<int> &nums, vector<vector<int>> &dp) {
        if (ind < 0) return 0;
        if (dp[ind][prev] != -1) return dp[ind][prev];
        if (prev == n || nums[ind] < nums[prev]) {
            // have 2 choices -> either add nums[ind] to LIS
            // or start a new LIS from nums[ind]
            return dp[ind][prev] = max(1 + solve(ind-1, ind, n, nums, dp),
                                       solve(ind-1, prev, n, nums, dp));
        }
        else {
            // since not strictly increasing start a new LIS from nums[ind]
            return dp[ind][prev] =  solve(ind-1, prev, n, nums, dp);
        }
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n-1, n, n, nums, dp);
    }
};