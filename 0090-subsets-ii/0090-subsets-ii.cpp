// index based appoach
// take not take index
class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& subset ) {
        if (i > nums.size()-1) {
            ans.push_back(subset);
            return ans;
        }
        subset.push_back(nums[i]);
        helper(nums, i+1, ans, subset);
        subset.pop_back();
        // since we have already picked the i-th element, need to check if the i+1 th element is same as i-th
        // if yes then skip picking again
        while (i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        helper(nums, i+1, ans, subset);
        return ans;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        return helper(nums, 0, ans, subset);
    }
};