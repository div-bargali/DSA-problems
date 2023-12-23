class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        // base case 
        if (i > j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxC = INT_MIN;
        // we will not find the first baloon to burst, because if we burst k, then we can't divide it
        // into 2 independent subproblems, because k-1 and k+1 will become adjacent
        // so we try to find the most optimal reverse order
        // so we will find the last balloon => then second last and so on
        // for last balloon left and right will be 1
        // for second last -> if it is on left of last -> then right will be last burst balloon and left will be 1
        
        for (int k = i; k <= j; k++) {
            maxC = max(maxC, 
                      nums[i-1]*nums[k]*nums[j+1]
                      + solve(i, k-1, nums, dp)
                      + solve(k+1, j, nums, dp));
        }
        return dp[i][j] = maxC;
    }
    
    int maxCoins(vector<int>& nums) {
        // insert 1 at start and end of nums
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n-2, nums, dp);
    }
};