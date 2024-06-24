class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            nums[i] %= 3;
            if (nums[i] != 0)
                cnt += min(nums[i], 3 - nums[i]);
        }
        return cnt;
    }
};