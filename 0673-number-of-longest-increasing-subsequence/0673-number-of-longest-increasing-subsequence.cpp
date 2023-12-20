class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int LIS = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    if (dp[prev] + 1 > dp[i]) {
                        dp[i] = dp[prev] + 1;
                        // whatever were the # of LIS until prev-index we add nums[i] to all
                        // so the # of LIS ending at index i will be same
                        cnt[i] = cnt[prev]; 
                    }
                    else if (dp[prev] + 1 == dp[i]) {
                        // since the lenght of LIS is not changing, but we have found another 
                        // so add the # of LIS until prev-index to the cnt of # of LIS at i
                        cnt[i] += cnt[prev];
                    }
                }
            }
            LIS = max(LIS, dp[i]);
        }
        int ans = 0; 
        for (int i = 0; i < n; i++) {
            // count the # of seq which has LIS length
            // example - nums = [2, 2, 2, 2]
            if (dp[i] == LIS) ans += cnt[i];
        }
        return ans;
    }
};