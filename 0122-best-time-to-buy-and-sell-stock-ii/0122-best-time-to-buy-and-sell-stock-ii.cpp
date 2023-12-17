class Solution {
public:
    // dp[i][t]-> rep max profit on day i, if a stock is not bought/sold on the day
    // dp[i][f] -> rep max profit on day i, if a stock is bought/not sold on the day
    
    int solve(int ind, int buy, int n, vector<int>& prices, vector<vector<int>> &dp) {
        // base case -> ind == n -> profit can be 0 -> buy/sell on same day
        if (ind == n) return 0;
        
        if (dp[ind][buy] != -1) return dp[ind][buy];
        
        int profit = 0;
        if (buy) {
            // buy -> take something from profit OR not buy
            profit = max(-prices[ind] + solve(ind+1, 0, n, prices, dp), 
                    solve(ind+1, 1, n, prices, dp)); 
        } else {
            // sell a stock OR hold the stock
            profit = max(prices[ind] + solve(ind+1, 1, n, prices, dp), 
                         solve(ind+1, 0, n, prices, dp)); 
        }
        return dp[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 1. recursion + memoization
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 1, n, prices, dp);
    }
};