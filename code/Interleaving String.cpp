class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool> > f(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if (f[i][j]) {
                    if (i != s1.size() && s1[i] == s3[i + j]) {
                        f[i + 1][j] = true;
                    }
                    if (j != s2.size() && s2[j] == s3[i + j]) {
                        f[i][j + 1] = true;
                    }
                }
            }
        }
        return f[s1.size()][s2.size()];
    }
};