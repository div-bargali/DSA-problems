class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // at max there can be only 2 elements that can appear more than n/3 times
        int elem1 = -1, elem2 = -1, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == elem1)
                cnt1++;
            else if (nums[i] == elem2)
                cnt2++;
            else if (cnt1 == 0 && nums[i] != elem2) {
                cnt1 = 1;
                elem1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != elem1) {
                cnt2 = 1;
                elem2 = nums[i];
            }
            else {
                cnt1--; cnt2--;
            }
        }
        // validate the count
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == elem1) cnt1++;
            else if (nums[i] == elem2) cnt2++;
        }
        if (cnt1 > floor(n/3)) ans.push_back(elem1);
        if (cnt2 > floor(n/3)) ans.push_back(elem2);
        return ans;
    }
};