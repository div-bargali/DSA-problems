class Solution {
public:
    void solve(vector<int>& nums, vector<int>& sub, vector<vector<int>>& ans, vector<bool>&freq) {
        if (sub.size() == nums.size()) {
            ans.push_back(sub);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]){
                sub.push_back(nums[i]);
                freq[i] = true;
                solve(nums, sub, ans, freq);
                freq[i] = false;
                sub.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        vector<bool> freq(nums.size(), false);
        solve(nums, sub, ans, freq);
        return ans;
    }
};