class Solution {
public:
    void solve(int i, vector<int>& sub, vector<vector<int>>& ans, int target, vector<int>& nums) {
        if ( i > nums.size() - 1 && target == 0) {
            ans.push_back(sub); return;
        }
        if (i < nums.size() && target >= 0) {
            if (target == 0) {
                ans.push_back(sub);
                return;
            }
            if (target - nums[i] >= 0) {
                sub.push_back(nums[i]);
                solve(i+1, sub, ans, target - nums[i], nums);
                sub.pop_back();
            } 
            while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
            solve(i+1, sub, ans, target, nums);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, sub, ans, target, candidates);
        return ans;
    }
};