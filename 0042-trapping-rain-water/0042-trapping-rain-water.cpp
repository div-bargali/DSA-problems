class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, maxLeft = height[0], right = height.size()-1, maxRight = height[right];
        int ans = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                // maxLeft is smaller, so height[i] can be compared with maxLeft only
                // also it is guranteed that of we find a value < maxLeft, we can store water
                // since maxLeft < maxRight
                if (height[left] < maxLeft) 
                    ans += maxLeft - height[left];
                else 
                    maxLeft = height[left];
                left++;
            } else {
                // maxRight is smaller, so height[i] should be compared with maxRight only
                if (height[right] < maxRight) 
                    ans += maxRight - height[right];
                else 
                    maxRight = height[right];
                right--;
            }
        }
        return ans;
    }
};