class Solution {
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if (i > j) return 0; // nothing left to cut
        
        if (dp[i][j] != -1) return dp[i][j];
        int minCost = INT_MAX;
        for (int k = i; k <= j; k++) {
            // when i == 1 and j == m-1
            // then cost will be n - 0 => n -> use same logic for other values of i & j
            minCost = min(minCost, 
                         cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp));
        }
        return dp[i][j] = minCost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        // its partitioning problem -> here we have to find the optimal partioning of the rod
        // based on the cuts array
        // we add 0 and n for computation of cost of a cut
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        // we are sorting so that when we partion cuts array, the 2 partitions are independent
        sort(cuts.begin(), cuts.end());
        return solve(1, m-2, cuts, dp);
    }
};