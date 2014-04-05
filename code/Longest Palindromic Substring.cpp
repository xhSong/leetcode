bool f[1010][1010];

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        int lx = 0, ly = 1;
        for (int len = 0; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len;
                if (len == 0 || len == 1) {
                    f[i][j] = true;
                } else {
                    f[i][j] = (f[i + 1][j - 1] && s[i] == s[j - 1]);
                    if (f[i][j] && ly - lx < len) {
                        lx = i, ly = j;
                    }
                }
            }
        }
        return s.substr(lx, ly - lx);
    }
};
