class Solution {
public:
    bool isValid(vector<string>& b, int n, int x, int y) {
        // Check row
        for (int j = y; j >= 0; j--) {
            if (b[x][j] == 'Q') return false;
        }
        // Check upper diagonals
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
            if (b[i][j] == 'Q') return false;
        }
        // Check lower diagonal
        for (int i = x, j = y; i < n && j >= 0; i++, j--) {
            if (b[i][j] == 'Q') return false;
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n, string(n, '.'));
        solve(ans, b, 0, n);
        return ans;
    }
    
    void solve(vector<vector<string>>& ans, vector<string>& b, int col, int n) {
        if (col == n) {
            ans.push_back(b);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(b, n, i, col)) {
                b[i][col] = 'Q';
                solve(ans, b, col + 1, n);
                b[i][col] = '.';
            }
        }
    }
};
