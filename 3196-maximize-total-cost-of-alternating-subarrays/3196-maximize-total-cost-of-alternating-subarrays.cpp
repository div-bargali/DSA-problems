class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        // using form 2 dp - ending at i
        int n = nums.size();
        vector<long long> dp(n, LLONG_MIN);
        // dp[i] stores max cost for subarray ending at i
        
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i], dp[i-1] + nums[i]); // if we partition at i for new subarray
            
            dp[i] = max(dp[i], (i >= 2 ? dp[i-2] : 0) + nums[i-1] - nums[i]); // if we partion at i-1 for new subarray
        }
        return dp[n-1];
    }
};