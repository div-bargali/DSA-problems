class Solution {
public:
    int tabulation(vector<int> &nums, int i, vector<int> &dp, int &ans) {
        if (i == 0) {
            ans = max(ans, nums[0]);
            return nums[0];
        }
        if (dp[i] != INT_MIN) return dp[i];
        
        int takeOld = tabulation(nums, i-1, dp, ans) + nums[i];
        int startNew = nums[i];
        dp[i] = max(takeOld, startNew);
        ans = max(ans, dp[i]);
        return dp[i];
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans;
        vector<int> dp(n, INT_MIN);
        // tabulation(nums, n-1, dp, ans);
        dp[0] = nums[0]; ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};