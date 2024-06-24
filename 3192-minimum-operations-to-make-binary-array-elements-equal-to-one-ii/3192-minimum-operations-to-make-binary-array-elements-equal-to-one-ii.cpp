class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flipCnt = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (flipCnt%2 == 0 && nums[i] == 0 || 
                flipCnt%2 == 1 && nums[i] == 1) {
                ans++;
                flipCnt++;
            }
        }
        return ans;
    }
};