// https://leetcode.com/problems/car-pooling/

// idea - sort on based of from and to
// remove overlaps add num passengers, travers trips again to check if num passengers > capacity 
// expaination - https://bit.ly/3eVxKvj O(nlogn)

// idea 2 - iterate trips and make an array cap, everytime we pickup from i cap[i] incr by num of passengers
// everytime we drop to j, cap[j] decr by num of pass, do prefix sum of cap, iterate cap and check if any cap[i] > capacity

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int cap[1001] = {0}, n = trips.size();
        for(int i = 0; i < n; ++i){
            cap[trips[i][1]] += trips[i][0];
            cap[trips[i][2]] -= trips[i][0];
        }
        
        int pref = 0;
        for(int i = 0; i < 1001; ++i){
            pref += cap[i];
            if(pref > capacity) return false;
        } 
        
        return true;
    }
    
};