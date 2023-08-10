class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, mid;
        if (h == l) return nums[l] == target;
        while (l <= h) {
            while (l < h && nums[l] == nums[l+1]) l++;
            while (l < h && nums[h] == nums[h-1]) h--;

            mid = l + (h - l )/2;
            if (nums[mid] == target) return true;
            if (nums[mid] >= nums[l]){
                // left side is fully sorted
                if (target >= nums[l] && target < nums[mid]) h = mid - 1;
                else l = mid + 1;
            } else {
                // right side is fully sorted
                if (target > nums[mid] && target  <= nums[h]) l = mid + 1;
                else h = mid - 1;
            }
        }
        return false;
    }
};