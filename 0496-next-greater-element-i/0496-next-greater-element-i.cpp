class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<pair<int, int>> stk;
        vector<int> ngr(nums2.size());
        
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }
        for (int i = nums2.size()-1; i >= 0; i--) {
            if (stk.empty()) {
                ngr[i] = -1;
                stk.push({nums2[i], i});
            } else {
                if (nums2[i] < stk.top().first) {
                    ngr[i] = stk.top().first;
                    stk.push({nums2[i], i});
                } else {
                    while (!stk.empty() && stk.top().first <= nums2[i])  {
                        stk.pop();
                    }
                    if (stk.empty()) {
                        ngr[i] = -1;
                    } else {
                        ngr[i] = stk.top().first;
                    }
                    stk.push({nums2[i], i});
                } 
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            int idx = mp[nums1[i]];
            int ngrElem = ngr[idx];
            ans.push_back(ngrElem);
        }
        return ans;
    }
};