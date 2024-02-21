class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        while (l <= h) {
            int mid = l + (h-l) / 2;
            // length will always be odd
            int numLeft, numRight;
            if (mid+1 <= h && nums[mid] == nums[mid+1]) {
                numRight = h - (mid+1);
                numLeft = mid - l;
                if (numRight % 2)
                    l = (mid+1) + 1;
                else 
                    h = mid - 1;
            } else if (mid-1 >= 0 && nums[mid] == nums[mid-1]) {
                numRight = h - mid;
                numLeft = (mid-1) - l;
                if (numRight % 2)
                    l = (mid) + 1;
                else 
                    h = (mid-1) - 1;
            } else {
                // mid is the single element
                return nums[mid];
            }
        }
        return -1;
    }
};