class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (m < n) // smaller array should be nums1
            return findMedianSortedArrays(nums2, nums1); // swap the arrays
        int totLen = n + m;
        // find num of elements to take in from nums1 for left half of combined array
        int l = 0; // take 0 elements
        int h = n; // take all elements
        while (l <= h) {
            int mid1 = l + (h-l) / 2;
            // if we take 2 elements from nums1 and totLen = 10, in left we will have 5
            // so take 5 - 2 = 3 from nums2
            int mid2 = (totLen + 1) / 2 - mid1; // we do +1 so that, if odd, median falss in left half
            // everything of left of mid1 and mid2 will be the left half of combined array
            int l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN; // if no elements from nums1 in left
            int l2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;
            int r1 = mid1 < n ? nums1[mid1] : INT_MAX; // if no elements from nums1 in right half
            int r2 = mid2 < m ? nums2[mid2] : INT_MAX;
            
            // check if split is valid
            // if the split is valid, then all elements in left half should be smaller
            // than all elements in right half. OR we can say, largest in left half should 
            // be smaller than smallest in right
            if (l1 <= r2 && l2 <= r1) {
                // median is the mean of largest in left and smallest in right if even
                if (totLen % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else 
                    return 1.0 * max(l1, l2); // left half will have more elements
            } 
            else if (l1 > r2) {
                h = mid1 - 1;
            }
            else 
                l = mid1 + 1;
        }
        return -1.0;
    }
};