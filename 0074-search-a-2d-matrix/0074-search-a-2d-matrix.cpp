class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        // find the correct row first
        int l = 0, h = n-1, ind = n-1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ind = h;
        cout << ind << endl;
        // ind will be index of last value in 0-th column that is < target
        // search in the ind-1 th row
        if (ind >= 0) {
            int k = upper_bound(matrix[ind].begin(), matrix[ind].end(), target) - matrix[ind].begin();
            if (k < 1)
                return false;
            return matrix[ind][k-1] == target;
        }
        return false;
    }
};