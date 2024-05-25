class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, k = 0, j;
        
        while (i < n) {
            j = i;
            int dup = 0;
            
            while (j < n && nums[i] == nums[j]) {
                if (dup < 2) {
                    nums[k] = nums[j];
                    k++; dup++;
                } 
                j++;
            }
            
            i = j;
        }
        return k;
    }
};