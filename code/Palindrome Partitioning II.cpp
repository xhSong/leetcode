class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool> > pali(s.size(), vector<bool> (s.size() + 1, false));
        for (int i = 0; i < n; ++i) {
            pali[i][i] = pali[i][i + 1] = true;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len;
                if (s[i] == s[j - 1] && pali[i + 1][j - 1]) {
                    pali[i][j] = true;
                }
            }
        }
        vector<int> f(n + 1, n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pali[j][i]) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[n] - 1;
    }
};