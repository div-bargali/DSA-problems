class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int elem = nums[0], cnt = 1;
        for (int i = 1; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                elem = nums[i];
            }
            else if (nums[i] == elem)
                cnt++;
            else 
                cnt--;
        }
        return elem;
    }
};