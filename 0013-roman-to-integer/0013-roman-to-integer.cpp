class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10; mp['L'] = 50; mp['C'] = 100;
        mp['D'] = 500; mp['M'] = 1000;
        
        int n = s.length(), ans = 0;
        // going in reverse
        for (int i = n-1; i >= 0; ) {
            char cur = s[i];
            if (i-1 >= 0) {
                char pre = s[i-1];
                if (mp[pre] < mp[cur]) {
                    // subtract the val of pre and then add
                    ans += (mp[cur] - mp[pre]);
                    i -= 2; // skipping the prev
                    continue;
                } 
            } 
            ans += mp[cur];
            i--;
        }
        return ans;
    }
};