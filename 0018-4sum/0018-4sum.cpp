class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(), j, k, l;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue; // avoid duplicates
            // 3-sum code
            for (j = i+1; j < n-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) 
                    continue;
                k = j+1, l = n-1;
                while(k < l) {
                    long long sum = nums[k]*1LL + nums[l]*1LL;
                    long long dif = target*1LL - nums[i]*1LL - nums[j]*1LL;
                    if (sum == dif) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        // avoid duplicates
                        while(k < l && nums[k] == nums[k+1])
                            k++;
                        while(k < l && nums[l] == nums[l-1])
                            l--;
                        k++;
                        l--;
                    }
                    else if (sum < dif)
                        k++;
                    else 
                        l--;
                }
            }
        }
        return ans;
    }
};