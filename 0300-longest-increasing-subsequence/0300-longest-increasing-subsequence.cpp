class Solution {
public:
    // Striver's approach // memoization + recursion
    int solve(int ind, int prev, int n, vector<int>&nums, vector<vector<int>>&dp) {
        if (ind == n) return 0;
        // we are shifting prev by 1 to right because prev -> -1 -> n-1 and -1 can't be stored
        // so prev -> 0 -> n
        if (dp[ind][prev+1] != -1) return dp[ind][prev+1];
        
        if (prev == -1 || nums[ind] > nums[prev])
            return dp[ind][prev+1] = max(1 + solve(ind+1, ind, n, nums, dp),
                                      solve(ind+1, prev, n, nums, dp));
        else 
            return dp[ind][prev+1] = solve(ind+1, prev, n, nums, dp);
    }
    
    int tabulation(int n, vector<int>& nums) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // base case is already covered by initialization with 0
        // reverse the loops for tabulation and copy recurence relation 
        for(int ind = n-1; ind >= 0; ind--) {
            for (int prev = ind-1; prev >= -1; prev--) {
                if (prev == -1 || nums[ind] > nums[prev]) {
                    dp[ind][prev+1] = max(1 + dp[ind+1][ind+1], 
                                         dp[ind+1][prev+1]);
                }
                else
                    dp[ind][prev+1] = dp[ind+1][prev+1];
            }
        }
        
        return dp[0][0];
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // Approach 1. Memo + Recursion
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(0, -1, n, nums, dp);
        
        // Approach 2. tabulation
        // return tabulation(n, nums);
        
        // Approach 3. Binary Search
        vector<int> temp;
        int ans = 1;
        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (temp.back() < nums[i]) {
                // everytime we add a new element in temp, it's means LIS's length is increasing
                temp.push_back(nums[i]); ans++;
            }
            else {
                // replace the element with the element which is just greater than nums[i]
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return ans;
    }
};