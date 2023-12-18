class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // whenever I'm selling I will pay the fee
        // space optimized solution
        int n = prices.size();
        vector<int> cur(2, 0);
        vector<int> ahead(2, 0);
        
        // base case
        ahead[0] = ahead[1] = 0; // for ind == n
        
        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if (buy)
                    profit = max(-prices[ind] + ahead[0], ahead[1]);
                else
                    profit = max(prices[ind] - fee + ahead[1], ahead[0]);
                cur[buy] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }
};