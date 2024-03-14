class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        bool neg = false;
        long long nn = n;
        if (n < 0) {
            neg = true; nn *= -1;
        }
        while (nn > 0) {
            if (nn%2) {
                ans *= x;
                nn--;
            } else {
                x = x * x;
                nn /= 2;
            }
        }
        if (neg) return 1.0 / ans;
        return ans;
    }
};