class NumArray {
public:
    vector<int> seg;
    int siz = 0;
    
    void build(int idx, int l, int r, vector<int> &nums) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2*idx+1, l, mid, nums);
        build(2*idx+2, mid+1, r, nums);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    int query(int idx, int low, int high, int l, int r) {
        if (low >= l && high <= r) {
            // complete overlap
            return seg[idx];
        }
        else if (high < l || low > r) {
            // no overlap
            return 0;
        }
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);
        return left + right;
    }
    
    void pointUpdate(int i, int idx, int val, int l, int r) {
        if (l == r) {
            seg[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            pointUpdate(2*i+1, idx, val, l, mid);
        } else {
            pointUpdate(2*i+2, idx, val, mid+1, r);
        }
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        siz = n;
        seg.resize(4*n);
        build(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        pointUpdate(0, index, val, 0, siz-1);
    }
    
    int sumRange(int left, int right) {
        // completely overlaps - return seg[idx]
        // partial overlaps - go left and right and return sum
        // no overlap - do nothing
        int l = 0, h = siz-1;
        return query(0, l, h, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
