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
    
    int tabulation(vector<int> &cuts, int m) {
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        // base case 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i > j) dp[i][j] = 0;
            }
        }
        
        // tabulation -> reverse the order
        // i will go from m-2 -> 1
        // j will go from i -> m-2
        for (int i = m-2; i >= 1; i--) {
            for (int j = i; j < m-1; j++) {
                int minCost = INT_MAX;
                for (int k = i; k <= j; k++) {
                    // when i == 1 and j == m-1
                    // then cost will be n - 0 => n -> use same logic for other values of i & j
                    minCost = min(minCost, 
                             cuts[j+1] - cuts[i-1] 
                                + dp[i][k-1] 
                                  + dp[k+1][j]);
                }
                dp[i][j] = minCost;
            }
        }
        return dp[1][m-2];
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
        // return solve(1, m-2, cuts, dp);
        return tabulation(cuts, m);
    }
};