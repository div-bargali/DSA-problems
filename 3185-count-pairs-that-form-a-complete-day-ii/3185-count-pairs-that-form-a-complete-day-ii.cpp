class Solution {
public:
    long long countCompleteDayPairs(vector<int>& nums) {
        unordered_map<int, int> past;
        long long ans = 0;
        past[nums[0] % 24] = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            int rev = (nums[i] % 24) != 0 ? 24 - (nums[i] % 24): 0;
            if (past.find(rev) != past.end()) {
                ans += past[rev];
            }
            if (past.find(nums[i] % 24) != past.end()) {
                past[nums[i] % 24]++;
            }
            else {
                past[nums[i] % 24] = 1;
            }
        }
        return ans;
    }
};