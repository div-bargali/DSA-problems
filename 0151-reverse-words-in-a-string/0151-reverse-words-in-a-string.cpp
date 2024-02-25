class Solution {
public:
    string reverseWords(string s) {
        // In-place reversal soln O(N) - TC
        // 1. reverse the complete string
        // 2. use 2 pointers to reverse the individual words
        reverse(s.begin(), s.end());
        int i = 0, n = s.length(), l = 0, r = 0;
        while (i < n) {
            while (i < n && s[i] != ' ') {
                s[r] = s[i]; // to remove extra spaces
                i++; r++;
            }
            if (l < r) {
                // reverse the word
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++; l = r;
            }
            i++;
        }
        // resize the string to remove trailing spaces
        s.resize(r-1);
        return s;
    }
};