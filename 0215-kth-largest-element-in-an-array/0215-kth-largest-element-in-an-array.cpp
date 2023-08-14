// create a max heap of size k
// iterate and insert, heap will balance itself
// after all inserts, remove k - 1 elements from heap
// remaining one is the number
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (minh.size() < k) {
                minh.push(nums[i]);
            } else {
                if(nums[i] > minh.top()) {
                    // cout << "before " << minh.top() << endl;
                    minh.pop();
                    minh.push(nums[i]);
                    // cout << "after " << minh.top() << endl;
                }
            }
        }
        return minh.top();
    }
};