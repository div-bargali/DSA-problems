class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // if last removed index was the max, remove it
            if (!dq.empty() && dq.front() == i-k) 
                dq.pop_front();
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            // remaining element on dq are greater or equal to nums[i]
            // place nums[i] at back
            dq.push_back(i);
            if (i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};