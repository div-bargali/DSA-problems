class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        // base case -> ind == n -> maxProfit = 0
        dp[n][0] = dp[n][1] = 0;
        dp[n+1][0] = dp[n+1][0] = 0;
        
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
                    // if stock is sold then can't buy on next day -> ind + 2
                    profit = max(prices[ind] + dp[ind+2][1], 
                                    dp[ind+1][0]); 
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1]; // on day 0 -> we can buy a stock
    }
};