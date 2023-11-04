class Solution {
public:
    // code of House Robber
    int solve(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        // base case
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> t1, t2;
        int n = nums.size();
        // 1st and last element can't be both in the answer
        // so either of them can only be in the answer. So we pick one of them and try
        // to find answer at a time. Later take max of both answers
        if (n == 1) return nums[0];
        for (int i = 0; i < n; i++) {
            if (i != 0) t2.push_back(nums[i]);
            if (i != n-1) t1.push_back(nums[i]);
        }
        int ans1 = solve(t1);
        int ans2 = solve(t2);
        return max(ans1, ans2);
    }
};