class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sSum = 0, dSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 9) dSum += nums[i];
            else sSum += nums[i];
        }
        return (sSum > dSum) | (sSum < dSum);
    }
};