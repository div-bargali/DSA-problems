class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxFreq = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end()) 
                mp[nums[i]] = 1;
            else 
                mp[nums[i]]++;
            maxFreq = max(maxFreq, mp[nums[i]]);
        }
        vector<vector<int>> freqList(maxFreq+1);
        // map the elements to the freqList
        // this is like a reverse frequency array/vector
        for (auto e: mp) {
            // key: nums[i] -> val: freq(nums[i])
            freqList[e.second].push_back(e.first);
        }
        vector<int> ans;
        for (int i = maxFreq; i >= 0, k > 0; ) {
            if (freqList[i].size() > 0) {
                ans.push_back(freqList[i].back());
                freqList[i].pop_back();
                k--;
            } else {
                i--;
            }
        }
        return ans;
    }
};