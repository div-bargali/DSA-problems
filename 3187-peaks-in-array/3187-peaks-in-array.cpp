class Solution {
public:
    vector<int> seg;
        
    vector<int> countOfPeaks(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        seg.resize(4*n);
        vector<int> peak(n, 0), ans;
        // pre compute the peaks in an array
        for (int i = 1; i < n-1; i++) {
            if (arr[i-1] < arr[i] && arr[i+1] < arr[i]) peak[i] = 1;
        }
        // build the initial segment tree
        buildTree(0, 0, n-1, peak);
        for (auto query: queries) {
            if (query[0] == 1) {
                int l = query[1], r = query[2];
                if (l == r) {
                    ans.push_back(0); continue;
                }
                int cntPeaks = queryTree(0, 0, n-1, l, r);
                // first and last element in a range can not be peaks
                if (peak[l]) cntPeaks--;
                if (peak[r]) cntPeaks--;
                ans.push_back(cntPeaks);
            }
            else {
                int id = query[1], val = query[2];
                arr[id] = val;
                // if index i is changed, then there can now be a peak at i, i-1 or i+1
                // so we check for all 3 indices
                for (int idx = id-1; idx <= id+1; idx++) {
                     if (idx-1 >= 0 && idx+1 < n) {
                        if (arr[idx-1] < arr[idx] && arr[idx+1] < arr[idx]) {
                            peak[idx] = 1;
                            update(0, 0, n-1, idx, 1);
                        } 
                        else {
                            peak[idx] = 0;
                            update(0, 0, n-1, idx, 0);
                        }
                    }
                }
            }
        }
        return ans;
    }
    
private:
    void buildTree(int ind, int low, int high, vector<int> &arr) {
        if (low == high) {
            seg[ind] = arr[low]; return;
        }
        int mid = low + (high - low) / 2;
        buildTree(2*ind+1, low, mid, arr);
        buildTree(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    } 
    
    int queryTree(int ind, int low, int high, int l, int r) {
        // no overlap
        if (high < l || low > r)
            return 0;
        // complete overlap
        else if (low >= l && high <= r)
            return seg[ind];
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = queryTree(2*ind+1, low, mid, l, r);
        int right = queryTree(2*ind+2, mid+1, high, l, r);
        return left + right;
    }
    
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val; return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid) 
            update(2*ind+1, low, mid, i, val); // left half
        else 
            update(2*ind+2, mid+1, high, i, val); // right half
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
};