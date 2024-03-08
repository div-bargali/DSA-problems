class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size(), j, k, i = 0;
        while (i < n-1) {
            j = i+1;
            k = n-1;
            int t = -nums[i];
            // 2-sum problem now
            while (j < k) {
                if (nums[j] + nums[k] == t) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j+1 < n && nums[j+1] == nums[j]) 
                        j++;
                    j++;
                    while(k-1 >= 0 && nums[k-1] == nums[k])
                        k--;
                    k--;
                }
                else if (nums[j] + nums[k] < t) {
                    while(j+1 < n && nums[j+1] == nums[j])
                        j++;
                    j++;
                } else {
                    while(k-1 >= 0 && nums[k-1] == nums[k])
                        k--;
                    k--;
                }
            }
            while(i < n-1 && nums[i+1] == nums[i])
                i++;
            i++;
        }
        return ans;
    }
};