// link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit = 0, minBuyPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minBuyPrice = min(minBuyPrice, prices[i]);
            mxProfit = max(mxProfit, prices[i] - minBuyPrice);
        }
        return mxProfit;
    }
};