class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 1, 2, 3, 4, 3 -> for 3 NGR is 4
        // if we consider a copied array 1, 2, 3, 4, 3 | 1, 2, 3, 4, 3
        // then it is easy to find NGR of 3
        // for 3, 1 should be the first element to consider, then 2 -> 1 should be inserted
        // last into stack
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n-1; i >= 0; i--) {
            stk.push(i); // storing index and not value for duplicates
        }
        // starting from last -> NGR
        for (int i = n-1; i >= 0; i--) {
            if (stk.empty()) {
                ans[i] = -1;
            }
            else {
                if (nums[i] < nums[stk.top()]) {
                    ans[i] = nums[stk.top()];
                    stk.push(i);
                } else {
                    while(!stk.empty() && nums[i] >= nums[stk.top()]) 
                        stk.pop();
                    if (stk.empty())
                        ans[i] = -1;
                    else {
                        ans[i] = nums[stk.top()];
                    }
                    stk.push(i);
                }
            }
        }
        return ans;
    }
};