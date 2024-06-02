class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        int n = m.size();
        sort(m.begin(), m.end()); 
        int count = 0;
        count += abs(m[0][0] - 1);
        for(int i = 1; i < n; i++){
            if(m[i][0] <= m[i-1][1]){ // no space between intervals
                if(m[i][1] < m[i-1][1]) m[i][1] = m[i - 1][1]; // merge if intervals are overlapping
            }
            else{ // space exists between intervals, add that space to count 
                int dy = m[i][0] - m[i-1][1];
                count += dy - 1; 
            }
        }
        count += abs(m[n-1][1] - days);
        return count;
    }
};