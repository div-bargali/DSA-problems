class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty()) left[i] = -1;
            else {
                if (heights[stk.top()] < heights[i]) {
                    left[i] = stk.top();
                } else {
                    while(!stk.empty() && heights[stk.top()] >= heights[i])
                        stk.pop();
                    if (stk.empty()) left[i] = -1;
                    else left[i] = stk.top();
                }
            }
            stk.push(i);
        }
        // clear the stack for re-use
        while(!stk.empty()) 
            stk.pop();
        int maxA = 0;
        for (int i = n-1; i >= 0; i--) {
            if (stk.empty()) right[i] = n-1;
            else {
                if (heights[stk.top()] < heights[i]) {
                    right[i] = stk.top()-1;
                } else {
                    while (!stk.empty() && heights[stk.top()] >= heights[i])
                        stk.pop();
                    if (stk.empty()) right[i] = n-1;
                    else right[i] = stk.top()-1;
                }
            }
            stk.push(i);
            int area = heights[i] * (right[i] - left[i]);
            maxA = max(maxA, area);
        }
        // for (auto e: left) cout << e << " ";
        // cout << endl;
        // for (auto e: right) cout << e << " ";
        return maxA;
    }
};