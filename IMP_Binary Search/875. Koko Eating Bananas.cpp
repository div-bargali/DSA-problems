// https://leetcode.com/problems/koko-eating-bananas/
// O(m.logn) TC

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size(), low = 1, high, mid, ans = 0;
        
        high = *max_element(piles.begin(), piles.end()); // gives the max element
        if(h == n) return high;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(hoursEat(piles, mid) <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
private:
    long long hoursEat(vector<int>& piles, long long m){
        long long ans = 0;
        for(auto e: piles){
            ans += (e % m) ? (e / m) + 1 : e / m;
        }
        return ans;
    }
};