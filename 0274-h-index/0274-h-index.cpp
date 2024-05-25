#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    int hIndex(vector<int>& citations) {
        // Binary Search approach - O(n.logn)
        return solveBinarySearch(citations);
    }
private:
    int solveBinarySearch(vector<int>& citations) {
        int n = citations.size();
        
        sort(citations.begin(), citations.end());
        
        int ans = 0;  // Initialize to 0 as h-index can be 0
        
        int l = 0, h = n;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            // Find the first paper with at least `mid` citations
            int idx = lower_bound(citations.begin(), citations.end(), mid) - citations.begin();
            int valid = n - idx;
            if (valid >= mid) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
