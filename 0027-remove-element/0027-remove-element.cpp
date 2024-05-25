class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = n-1;
        while (i <= j) {
            if (nums[i] == val) {
                // first check j
                if (nums[j] == val) j--;
                else {
                    swap(nums[i], nums[j]);
                    i++; j--;
                }
            } else {
                i++;
            }
        }
        return j + 1;
    }
};