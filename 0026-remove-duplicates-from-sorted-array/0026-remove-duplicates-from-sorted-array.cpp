class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while (i < n && j < n) {
            while (j > i && j < n && nums[j] == nums[i])
                j++;
            if (j < n && nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};