class Solution {
public:
    bool isValid(vector<vector<char>>&b, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // check row
            if (b[i][col] == c) return false;
            // check col
            if (b[row][i] == c) return false;
            // check 3 x 3 subgrid;
            int startRow = 3 * (row / 3);
            int startCol = 3 * (col / 3);
            if (b[startRow + i/3][startCol + i % 3] == c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& b) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') {
                    // check all numbers
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(b, i, j, c)) {
                            b[i][j] = c;
                            if (solve(b)) {
                                return true;
                            }
                            b[i][j] = '.';
                        }
                    }
                    // iterated all 9 numbers and could not solve board
                    // so return false
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};