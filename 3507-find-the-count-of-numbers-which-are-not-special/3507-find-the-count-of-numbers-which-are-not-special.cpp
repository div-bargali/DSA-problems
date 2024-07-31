class Solution {
public:
    vector<int> prime;
    int nonSpecialCount(int l, int r) {
        prime.resize(sqrt(r)+1, 1);
        prime[0] = prime[1] = 0;
        sieve(sqrt(r));
        int cnt = 0;
        // check if square btw limits
        for (int i = sqrt(l); i <= sqrt(r); i++) {
            if (prime[i] && i*i <= r && i*i >= l) cnt++; 
        }
        return (r-l+1) - cnt;
    }
private:
    void sieve(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (prime[i] == 1) {
                for (int j = i*i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
    }
};