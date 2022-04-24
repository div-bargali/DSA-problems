// link - https://leetcode.com/problems/maximum-subarray/

// TC - O(N) SC - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // what is the max subarry sum if ends at index i
        int n = nums.size(), maxSum = nums[0], sumSoFar = nums[0];
//         vector<int> dp(n, INT_MIN);
        
//         dp[0] = nums[0];
//         int maxSum = dp[0];
        
//         if(n==1) return dp[0];
        
        
        for (int i = 1 ; i < n; i++){
            // choice - start a new subaray from this index or add to current subarray
            sumSoFar = max(sumSoFar + nums[i], nums[i]);
            maxSum = max(maxSum, sumSoFar);
        }
        return maxSum;
    }
};