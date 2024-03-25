class Solution {
public:
    void cntPairBeforeMerge(int l, int mid, int h, int &ans, vector<int> &nums) {
        int right = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (right <= h && (long long) nums[i] > 2LL * nums[right]) right++;
                ans += (right - (mid + 1));
        }
    }
    
    void merge(int l, int mid, int h, vector<int> &nums) {
        vector<int> merge;
        int i = l, j = mid+1;
        while(i <= mid && j <= h) {
            if (nums[i] < nums[j]) {
                merge.push_back(nums[i]); i++;
            } else {
                merge.push_back(nums[j]); j++;
            }
        }
        while (i <= mid) merge.push_back(nums[i++]);
        while (j <= h) merge.push_back(nums[j++]);
        // put the elems of merged array into nums
        for (int i = 0; i < merge.size(); i++) 
            nums[l + i] = merge[i];
    }
    
    void solve(int l, int h, vector<int> &nums, int &ans) {
        if (l >= h) return;
        int mid = l + (h - l) / 2;
        solve(l, mid, nums, ans);
        solve(mid+1, h, nums, ans);
        cntPairBeforeMerge(l, mid, h, ans, nums);
        merge(l, mid, h, nums);
    } 
    
    int reversePairs(vector<int>& nums) {
        int ans = 0, h = nums.size() - 1, l = 0;
        solve(l, h, nums, ans);
        return ans;
    }
};