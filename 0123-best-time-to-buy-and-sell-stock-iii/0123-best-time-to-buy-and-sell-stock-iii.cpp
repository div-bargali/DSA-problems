class Solution {
public:
    int solve(int ind, int buy, int cnt, int n, int k, vector<int> &p, vector<vector<vector<int>>> &dp) {
        // base case 
        if (ind == n || cnt > k) return 0; // no more transactions can be made -> 0 profit
        if (dp[ind][buy][cnt] != -1) return dp[ind][buy][cnt];
        int profit = 0;
        // cnt will only increase when we sell
        if (buy) 
            profit = max(-p[ind] + solve(ind+1, 0, cnt+1, n, k, p, dp),
                            solve(ind+1, 1, cnt, n, k, p, dp));
        else 
            profit = max(p[ind] + solve(ind+1, 1, cnt+1, n, k, p, dp),
                            solve(ind+1, 0, cnt, n, k, p, dp));
        return dp[ind][buy][cnt] = profit;
    } 
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k = 4;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, 0, n, k, prices, dp);
    }
};