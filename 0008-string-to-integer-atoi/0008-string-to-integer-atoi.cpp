class Solution {
public:
    int myAtoi(string s) {
        // start from the end
        int n = s.length();
        bool positive = true;
        int ans = 0, i = 0;
        while (i < n && s[i] == ' ')
            i++; // skipping leading whitespace
        // next char can be + or - or a digit
        if (s[i] == '-') {
            positive = false; i++;
        } else if (s[i] == '+') {
            i++;
        }
        for (i; i < n; i++) {
            if (s[i] < '0' || s[i] > '9') {
                // char is not a digit, skip reading 
                break; 
            } else {
                int digit = s[i] - '0'; // to find the value
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                    return positive ? INT_MAX : INT_MIN;
                }
                ans = (ans * 10) + digit;
            }
        }
        return positive ? ans : -ans;
    }
};