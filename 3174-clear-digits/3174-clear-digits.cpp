class Solution {
public:
    string clearDigits(string s) {
        // in place removal using 2 pointers
        int i = 0, n = s.length();
        for (int j = 0; j < n; j++) {
            if (!isdigit(s[j])) {
                s[i] = s[j];
                i++;
            } else {
                i--;
            }
        }
        return s.substr(0, i);
    }
};
