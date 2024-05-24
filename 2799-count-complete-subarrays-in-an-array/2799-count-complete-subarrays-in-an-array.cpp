class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(); 
        set<int> num_set(nums.begin(), nums.end());
        int dist_cnt = num_set.size();
        unordered_map<int, int> freq;
        
        int i = 0, j = 0, uniq = 0, ans = 0;
        while (i < n && j < n) {
            if (freq.find(nums[j]) == freq.end() || freq[nums[j]] == 0) {
                freq[nums[j]] = 1;
                uniq++;
            } else {
                freq[nums[j]]++;
            }
            
            while (uniq == dist_cnt) {
                // if (i to j) has uniq cnt == dist_cnt in complete array
                // then everything on right of j, is going to be repeated elements
                // so all subarrays starting from i and ending at j, or after j will be valid
                ans += (n - j); 

                // move left pointer
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) uniq--;
                i++; 
            }
            j++;
        }
        return ans;
    }
};