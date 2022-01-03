// https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        vector<int> indeg(n+1, 0);
        for(int i = 0; i < m; ++i){
            indeg[trust[i][0]]--; // a(i) trusts someone else 
            indeg[trust[i][1]]++; // b(i) is trusted by someone else
        }
        
        for(int i = 1; i <= n; ++i){
            if(indeg[i] == n-1){
                return i; // this person is trusted by every other person
            }
        }
        
        return -1;
    }
};