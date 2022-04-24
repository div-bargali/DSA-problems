// link - https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

//         NON - Space Optimised soln

//         vector<int> zeroRow(n, 0), zeroCol(m, 0);
        
//         // identify rows and cols thta have to be 0
//         for(int i = 0; i < n; ++i){
//             for(int j = 0; j < m; ++j){
//                 if(matrix[i][j]==0){
//                     zeroRow[i] = 1;
//                     zeroCol[j] = 1;
//                 }
//             }
//         }
        
//         // set the zero rows
//         for(int i = 0; i < n; ++i){
//             for(int j = 0; j < m; ++j){
//                 if(zeroRow[i] == 1 || zeroCol[j]== 1){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
        
        // in-place solution - pretty similar to the above one
        
        // identify rows and cols thta have to be 0
        // use first cell of every row and col as a flag
        // for first col use col0 variable
        bool col0 = false;
        
        for(int i = 0; i < n; ++i){
            // check for first col
            if(matrix[i][0] == 0 ) col0 = true;
            for(int j = 1; j < m; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // set the zero rows using flag
        // handle for all except 0th row and col
        for(int i = 1; i < n; ++i){
            for(int j= 1; j < m; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // handle 0th row
        if(matrix[0][0] == 0){
            for(int j = 0; j < m; ++j) matrix[0][j] = 0;
        }
        
        if(col0){
            for(int i = 0; i < n; ++i) matrix[i][0] = 0;
        }
    }
        
};