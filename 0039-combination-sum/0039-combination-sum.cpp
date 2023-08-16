// initial idea - for each index, we have 2 choices - take or move to next
// maintain sum in state
class Solution {
public:
    void solve(int i, vector<int>& sub, vector<vector<int>>& ans, int sum, int target, vector<int>& nums) {
        if (i < nums.size() && sum <= target) {
            if (sum == target) {
                ans.push_back(sub);
                return;
            }
            if (sum + nums[i] <= target) {
            sum += nums[i];
            sub.push_back(nums[i]);
            solve(i, sub, ans, sum, target, nums);
            sub.pop_back();
            sum -= nums[i];
            }
            solve(i+1, sub, ans, sum, target, nums);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(0, sub, ans, 0, target, candidates);
        return ans;
    }
};