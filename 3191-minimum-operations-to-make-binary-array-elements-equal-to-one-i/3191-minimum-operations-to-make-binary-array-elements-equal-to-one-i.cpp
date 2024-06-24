class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0, j, ans = 0, n = nums.size();
        while(i < n) {
            if (nums[i] == 0) {
                ans++;
                j = i;
                if (j+2 < n) {
                    for (; j < n && j <= i+2; j++) {
                        nums[j] ^= 1;
                    }
                }
            }
            i++;
        }
        for (auto e: nums) {
            if (e == 0) return -1;
        }
        return ans;
    }
};