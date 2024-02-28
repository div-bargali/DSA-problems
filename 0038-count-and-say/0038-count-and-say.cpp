class Solution {
public:
    string countAndSay(int n) {
       if (n == 1) // base case
           return "1";
        if (n == 2)
            return "11";
        // solve for smaller first
        string rec = countAndSay(n-1); 
        // while backtracking do-something
        // split the string into min sunstrings, such that each substring has 1 unique digit
        // 1211 is split as 1 | 2 | 1 1
        int i = 0, j = 1;
        string ans = "";
        while (i < rec.length() && j < rec.length()) {
            if (rec[j] == rec[i]) {
                j++;
            } else {
                int count = j - i;
                ans += to_string(count);
                ans += rec[i];
                i = j; j++;
            }
        }
        if (i < rec.length()) {
            int count = j - i;
            ans += to_string(count);
            ans += rec[i];
        }
        return ans;
    }
};