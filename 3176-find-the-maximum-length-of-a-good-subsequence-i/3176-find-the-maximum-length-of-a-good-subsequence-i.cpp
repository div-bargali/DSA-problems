class Solution {
public:
    int dp[502][502][26];
    
    int solve(int ind, int prev, int k, vector<int>& nums) {
        if (ind == nums.size()) return 0;
        
        if (dp[ind][prev+1][k] != -1) return dp[ind][prev+1][k];
        
        // take not take
        if (prev == -1 || nums[ind] == nums[prev]) {
            // take or not take choice
            dp[ind][prev+1][k] = max(1 + solve(ind+1, ind, k, nums), 
                                     solve(ind+1, prev, k, nums)); 
            // +1 is done to prev because prev starts from -1, so prev = 0, will store the value for -1
        } else {
            if (k > 0) {
                // take oe not take choice
                dp[ind][prev+1][k] = max(1 + solve(ind+1, ind, k-1, nums),
                                        solve(ind+1, prev, k, nums));
            } else {
                // can't take in this case
                dp[ind][prev+1][k] = solve(ind+1, prev, k, nums);
            }
        }
        return dp[ind][prev+1][k];
    }
    
    int solveTabulation(vector<int> &nums, int k) {
        int n = nums.size(), LGS = 1;
        // dpp[i][k] will store the length of the LGS that ends at index i and has k unequal pairs
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        // base case - if k = 0, the dp[0..n-1][0] = 1, we can have atleast 1 element
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                for (int j = 0; j <= k; j++) {
                    if (nums[i] == nums[prev]) {
                        dp[i][j] = max(dp[i][j], 1 + dp[prev][j]);
                    } 
                    else if (j > 0) {
                        dp[i][j] = max(dp[i][j], 1 + dp[prev][j-1]);
                    }
                    LGS = max(LGS, dp[i][j]);
                }
            }
        }
        return LGS;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        // return solve(0, -1, k, nums);
        
        return solveTabulation(nums, k);
    }
};