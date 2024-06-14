class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[i][j] represents the maximum length of subsequence ending at index i with at most j changes
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        int ans = 0;
        
        for (int j = 0; j <= k; j++) {
            unordered_map<int, int> max_for_same_val;
            int max_for_diff_j_1 = 0;
            for (int i = 0; i < n; i++) {
                // Initialize dp[i][j] to at least 1
                dp[i][j] = 1;

                // Case when previous value picked is the same as nums[i]
                if (max_for_same_val.find(nums[i]) != max_for_same_val.end()) {
                    dp[i][j] = max(dp[i][j], 1 + max_for_same_val[nums[i]]);
                }
                
                // Case when previous value picked was not the same
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], 1 + max_for_diff_j_1);
                }
                
                // Update the answer
                ans = max(ans, dp[i][j]);
                
                // Update max_for_same_val for current nums[i]
                max_for_same_val[nums[i]] = max(max_for_same_val[nums[i]], dp[i][j]);
                
                // Update max_for_diff_j_1 for future elements
                if (j > 0) {
                    max_for_diff_j_1 = max(max_for_diff_j_1, dp[i][j - 1]);
                }
            }
        }
        return ans;
    }
};