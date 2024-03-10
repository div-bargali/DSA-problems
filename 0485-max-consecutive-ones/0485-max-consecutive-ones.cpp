class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, n = nums.size(), ans = 0;
        int cnt = 0;
        while (i < n) {
            while(i < n && nums[i] == 1) {
                i++; cnt++;
            }
            ans = max(ans, cnt);
            cnt = 0;
            i++;
        }
        return ans;
    }
};