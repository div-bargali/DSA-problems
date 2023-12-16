class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuyPrice = INT_MAX;
        int maxProfit = 0, n = prices.size();
        for (int i = 0; i < n; i++) {
            minBuyPrice = min(minBuyPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minBuyPrice);
        }
        return maxProfit;
    }
};