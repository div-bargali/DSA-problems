class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        if (n != m) return false;
        vector<int> freq(26, 0); // for 26 lower case letters
        
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        // if length is same and freq of the chars in both string is same
        // we can re-arrange s, to make t. so freq of char in a - freq of char in b should be 0
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }
        return true;
    }
};