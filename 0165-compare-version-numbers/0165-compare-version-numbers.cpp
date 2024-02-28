class Solution {
public:   
    int compareVersion(string version1, string version2) {
        long long s1 = 0, s2 = 0;
        int i = 0, j = 0;
        int n = version1.length(), m = version2.length();
       
        if (version1[n-1] != '.') version1.append(".");
        if (version2[m-1] != '.') version2.append(".");
        while (i < n || j < m) {
            while (i < n && version1[i] != '.') {
                s1 = s1 * 10 + version1[i] - '0'; // digit
                i++;
            } 
            while (j < m && version2[j] != '.') {
                s2 = s2 * 10 + version2[j] - '0'; // digit
                j++;
            }
            if (s1 < s2) return -1;
            else if (s1 > s2) return 1;
            else {
                if (version1[i] == '.') s1 = 0;
                if (version2[j] == '.') s2 = 0;
            }
            i++; j++;
        }
        if (s1 < s2) return -1;
        else if (s1 > s2) return 1;
        return 0;
    }
};