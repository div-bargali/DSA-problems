class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), i = 0, j = 0; 
        unordered_map<char, int> mp; // Use char as key, not int
        int len = 0;
        while (i < n && j < n) {
            len = max(len, j - i); 
            if (mp.find(s[j]) != mp.end()) {
                // Character exists in map already
                i = max(mp[s[j]] + 1, i); // Move i to one position to the right of s[j]
            }
            mp[s[j]] = j; 
            j++;
        }
        len = max(len, j - i); // Update len after the loop ends
        return len;
    }
};