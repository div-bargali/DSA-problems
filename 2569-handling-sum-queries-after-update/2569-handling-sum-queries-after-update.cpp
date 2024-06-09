class Solution {
public:
    vector<int> seg;
    vector<int> lazy;
    
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        seg.resize(4*n);
        lazy.resize(4*n, 0);
        build(0, 0, n-1, nums1);
        
        vector<long long> ans;
        long long sm = accumulate(begin(nums2), end(nums2), 0LL);
        for (auto q: queries) {
            if (q[0] == 1) 
                updateRange(0, 0, n-1, q[1], q[2]); // idx, low, high, l, r
            else if (q[0] == 2) {
               sm += (long long)seg[0] * q[1]; // # of 1's in nums1 * p
            }
            else               
                ans.push_back(sm);
        }
        return ans;
    }
private:
    void build(int idx, int l, int r, vector<int> &nums1) {
        if (l == r) {
            seg[idx] = nums1[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2*idx+1, l, mid, nums1);
        build(2*idx+2, mid+1, r, nums1);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2]; //
        return;
    }
    
    void updateRange(int idx, int low, int high, int l, int r) {
        // update the range first
        int rangeCnt = high - low + 1;
        if (lazy[idx] != 0) {
            // flip the # of 1's in this range
            // 0, 1, 1 -> 1, 0, 0 (cnt = 3, seg[idx] = 2)  -> updated to 3 - 2 = 1
            seg[idx] = rangeCnt - seg[idx];  
            if (low != high) {
                lazy[2*idx+1] ^= 1; // propagate the lazy updates to child nodes
                lazy[2*idx+2] ^= 1;
            }
            lazy[idx] = 0;
        }
        // if complete overlap
        if (low >= l && high <= r) {
            seg[idx] = rangeCnt - seg[idx];
            if (low != high) {
                lazy[2*idx+1] ^= 1; // propagate the lazy updates to child nodes
                lazy[2*idx+2] ^= 1;
            }
            return;
        } 
        else if (high < l || low > r) return; 
        else {
            // partial overlap
            int mid = low + (high - low) / 2;
            updateRange(2*idx+1, low, mid, l, r);
            updateRange(2*idx+2, mid+1, high, l, r);
            seg[idx] = seg[2*idx+1] + seg[2*idx+2];
            return;
        }  
    }
    
    int query(int idx, int low, int high, int l, int r) {
        int rangeCnt = high - low + 1;
        if (lazy[idx] != 0) {
            seg[idx] = rangeCnt - seg[idx];  
            if (low != high) {
                lazy[2*idx+1] ^= 1; // propagate the lazy updates to child nodes
                lazy[2*idx+2] ^= 1;
            }
            lazy[idx] = 0;
        }
        if (low > r || high < l) return 0;
        else if (low >= l && high <= r) return seg[idx];
        int mid = low + (high - low) / 2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);
        return left + right;
    }
};