class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen(s), m = strlen(p);
        vector<vector<bool> > f(n + 1, vector<bool> (m + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i && j && p[j - 1] == '.') {
                    f[i][j] = f[i - 1][j - 1];
                } else if (j >= 2 && p[j - 1] == '*') {
                    if (p[j - 2] == '.') {
                        f[i][j] = (f[i][j - 2] || (i && f[i - 1][j]));
                    } else {
                        f[i][j] = (f[i][j - 2] || (i && s[i - 1] == p[j - 2] && f[i - 1][j]));
                    }
                } else if (i && j){
                    f[i][j] = (f[i - 1][j - 1] && s[i - 1] == p[j - 1]);
                }
            }
        }
        return f[n][m];
    }
};