class Solution {
public:
    int MOD = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int> pref(n, 1);
        
        while (k--) {
            for (int i = 1; i < n; i++) {
                pref[i] = (pref[i] % MOD + pref[i-1] % MOD) % MOD;
            }
        }
        return pref[n-1];
    }
};