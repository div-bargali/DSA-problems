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
    
    int maxProfit2d_DP(vector<int>& prices) {
        int n = prices.size();
        // 1. recursion + memoization
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solve(0, 1, n, prices, dp);
        
        // 2. Tabluation
         vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // base case -> ind == n -> maxProfit = 0
        dp[n][0] = dp[n][1] = 0;
        
        // reverse the loop -> 0 -> n will become n-1 -> 0
        // copy the memoization part as it is
        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    // buy -> take something from profit OR not buy
                    profit = max(-prices[ind] + dp[ind+1][0], 
                                dp[ind+1][1]); 
                } else {
                    // sell a stock OR hold the stock
                    profit = max(prices[ind] + dp[ind+1][1], 
                                    dp[ind+1][0]); 
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1]; // on day 0 -> we can buy a stock
    }
    
    // 3. Space Optimization 
    int maxProfit(vector<int> &prices) {
        // dp[i][j] depends on only dp[i+1][0/1]
        // so insetad of 2D dp we can make it 1D
        int n = prices.size();
        vector<int> ahead(2, 0); // this is for ind+1
        vector<int> cur(2, 0);
        
        // base case
        ahead[0] = ahead[1] = 0;
        
        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                 if (buy) {
                    // buy -> take something from profit OR not buy
                    profit = max(-prices[ind] + ahead[0], 
                                ahead[1]); 
                } else {
                    // sell a stock OR hold the stock
                    profit = max(prices[ind] + ahead[1], 
                                    ahead[0]); 
                }
                cur[buy] = profit;
                ahead = cur;
            }
        }
        return ahead[1]; // equivalent to -> dp[0][1]
    }
};