// link - https://leetcode.com/problems/pascals-triangle/   

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> arr(n);
        
        for(int i = 0; i < n ; ++i){
            arr[i].resize(i + 1);
            arr[i][i] = arr[i][0] = 1;
            for (int j = 1; j < i; ++j){
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }

        return arr;
    }
};