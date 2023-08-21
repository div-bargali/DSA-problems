class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1; // calculate (n-1)!
        vector<int> nums;
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i); // sorted array of numbers 1 to n
        }
        nums.push_back(n);
        string ans = "";
        k = k - 1; // 0 based indexing
        while(true) {
            int idxToPick = k / fact; // when 1st number is fixed there are (n-1)! permutations for the remaining string
            // so the (k-1)th permutation should be found when the number at index (k-1)/fact is selected
            ans += to_string(nums[idxToPick]);
            nums.erase(nums.begin() + idxToPick); // remove the picked number
            if (nums.size() == 0) break; // no more numbers to pick
            k = k % fact;   // the find the next number to be picked
            fact /= nums.size(); // since size of nums has decreased by 1, so num of permutations will also decrease

        }
        return ans;
    }
};