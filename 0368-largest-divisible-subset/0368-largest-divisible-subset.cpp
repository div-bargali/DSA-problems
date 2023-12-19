class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // if b is divisible by a && c is divisible by b => c is also divisible by a
        // so we can use same code as LIS, but now we need to check that nums[ind] is divisible by nums[prev]
        
        // we will use the LIS - algo approach II
        // dp[i] will store longest length of the sequence that ends at index i
        int n = nums.size();
        vector<int> dp(n, 1);
        // we are sorting because a) it's subset / order does not matter 
        // and b) it helps because we will have to check divisibility in only 1 direction
        sort(nums.begin(), nums.end()); 
        
        int ans = 1;

        for (int i = 1; i < n; i++) {
            for (int prev = i-1; prev >= 0; prev--) {
                if (nums[i] % nums[prev] == 0) {
                    dp[i] = max(1 + dp[prev],  // either take nums[prev]
                               dp[i]);  // or don't take
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        // now backtrack the dp vector -> LDS will be in reverse order
        int len = ans-1, prev = 0;
        vector<int> res(ans, 0);
        
        for (int i = n-1; i >= 0 && len>=0; i--) {
            if (dp[i] == ans && prev % nums[i] == 0) {
                res[len] = nums[i];
                ans--; len--;
                prev = nums[i];
            }
        }
        
        return res;
    }
};