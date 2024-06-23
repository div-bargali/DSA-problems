class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double ans = 10000.0;
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            ans = min(ans, (nums[l] + nums[h]) / 2.0);
            l++; h--;
        }
        return ans;
    }
};