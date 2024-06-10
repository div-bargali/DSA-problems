class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int idx = 0, maxSkill = skills[0], wins = 0;
        
        // if k >= n, then player will max skill will always win
        // for k < n, we will have to check
        for (int i = 1; i < n; i++) {
            if (skills[i] > maxSkill) {
                maxSkill = skills[i];
                idx = i;
                wins = 1;
            } 
            else 
                wins++;
            if (wins == k) 
                return idx;
        }
        // if n-1 iterations are over then player with maximum skill will be at front
        // this player will be the ans now, cus no one can beat him
        return idx;
    }
};