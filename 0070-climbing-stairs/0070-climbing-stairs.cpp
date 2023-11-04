class Solution {
public:
    int climbStairs(int n) {
        // if standing at 0th stair there is 1 way to reach it
        // if standing at 1st stair there is 1 way to reach it
        int prev0 = 1, prev1 = 1;
        for (int i = 2; i <= n; i++){
            int cur = prev0 + prev1;
            prev0 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};