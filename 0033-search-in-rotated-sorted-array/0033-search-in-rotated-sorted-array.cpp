class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        while (l <= h) {
            int mid = l + (h-l) / 2;
            if (nums[mid] == target) return mid;
            // identify the sorted half - one half will definitely be sorted - observation
            if (nums[mid] <= nums[h]) {
                // right half is sorted
                if (nums[mid] <= target && target <= nums[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            } 
            else {
                // left half is sorted
                if (nums[l] <= target && target <= nums[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};