class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)
            return "";
        if (n == 1)
            return strs[0];
        string s1 = strs[0];
        int ans = s1.length();
        for (int i = 1; i < n; i++) {
            int j = 0;
            while(j < strs[i].length() && s1[j] == strs[i][j]) 
                j++;
            ans = min(ans, j);
        }
        return s1.substr(0, ans);
    }
};