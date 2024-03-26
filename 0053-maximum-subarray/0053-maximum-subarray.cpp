class Solution {
public:
    int solve(vector<int> &nums, int i, vector<int> &dp, int &ans) {
        if (i == 0) {
            ans = max(ans, nums[0]);
            return nums[0];
        }
        if (dp[i] != INT_MIN) return dp[i];
        
        int takeOld = solve(nums, i-1, dp, ans) + nums[i];
        int startNew = nums[i];
        dp[i] = max(takeOld, startNew);
        ans = max(ans, dp[i]);
        return dp[i];
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        vector<int> dp(n, INT_MIN);
        solve(nums, n-1, dp, ans);
        return ans;
    }
};