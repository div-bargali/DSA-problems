class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int b = target - nums[i];
            if (mp.find(b) == mp.end()) {
                mp[nums[i]] = i;
            } else {
                // a + b = target
                return {mp[b], i};
            }
        }
        return {-1, -1};
    }
};