// similar to shortest path from root to leaf in a binary tree
// one approach can be to use BFS? for each level push the child noddes and recurse until you hit bottom 
// keep track of the sum from left and right

// recursion - 
// compute sum of all paths from top to bottom and then pick the minimum path
class Solution {
public:
    int solve(int level, int prev, int n, vector<vector<int>>& triangle) {
        if (level == n-1) {
            return triangle[level][prev];
        }
        if (level+1 < n) {
            int left = solve(level+1, prev, n, triangle);
            int right = solve(level+1, prev+1, n, triangle);
            return min(left, right) + triangle[level][prev];
        }
        return -1;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return solve(0, 0, n, triangle); // memoize this for dp answer
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int prevL = INT_MAX, prevR = INT_MAX;
                if(j <= i) {
                    if (j-1 >= 0) prevL = dp[i-1][j-1];
                    if (j != i) prevR = dp[i-1][j];
                    dp[i][j] = triangle[i][j] + min(prevL, prevR);
                }
            }
        }
        int minE = INT_MAX;
        for (auto e : dp[n-1]) minE = min(e, minE);
        return minE;
    }
};