// there can be 2 different ways a subarray of the main array is valid
// 1. one half of the partition has exactly 2 elements equal
// 2. one half of the partition has exactly 3 elements equal
// any subarray[0 - i] will be valid if either of conditions 1 or 2 are met
// and also the remaining half is 3 consecutive increasing elements
class Solution {
public:
    int n;
    vector<int> dp;
    bool f(int i, vector<int>& nums){
        if (i<0) return 1;
        if (i==0) return 0; //if there is only number left
        if (dp[i]!=-1) return dp[i]==1;
        bool b0=0, b1=0, b2=0;
        if (i > 0 && nums[i] == nums[i-1]) 
            b0=f(i-2, nums);
        if (i > 1 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2])
            b1=f(i-3, nums);
        if (i > 1 && nums[i] == nums[i-1]+1 && nums[i-1] == nums[i-2]+1)
            b2=f(i-3, nums);
    //    cout<<i<<":"<<b0<<","<<b1<<","<<b2<<endl;
        return dp[i]=b0||b1||b2;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        return f(n-1, nums);
    }
};
