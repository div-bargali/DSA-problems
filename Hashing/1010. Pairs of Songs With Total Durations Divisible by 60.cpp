// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), cnt = 0;
        vector<int> freq(60, 0);
        for(int i = 0; i < n; ++i){
            freq[time[i] % 60]++;
        }
        
        // check all pairs from 1 - 29 (not from 1 - 59 because that way we count pair twice)
        for(int i = 1; i < 30; i++){
            cnt += freq[i] * freq[60 - i];
        }
        if(freq[30]){
            cnt += (freq[30]) * (freq[30] - 1) / 2;
        }
        if(freq[0]){
            cnt += (freq[0]) * (freq[0] - 1) / 2;
        }
        
        return cnt;
    }
};