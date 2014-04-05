class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble(s1.c_str(), s2.c_str(), s1.size());
    }
private:
    bool isScramble(const char *s1, const char *s2, int n) {
        if (n == 0) return true;
        if (n == 1) return s1[0] == s2[0];
        vector<int> cnt(256, 0);
        for (int i = 0; i < n; ++i) {
            ++ cnt[s1[i]];
        }
        for (int i = 0; i < n; ++i) {
            -- cnt[s2[i]];
            if (cnt[s2[i]] < 0) return false;
        }
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1, s2, i) && isScramble(s1 + i, s2 + i, n - i)) {
                return true;
            }
            if (isScramble(s1, s2 + n - i, i) && isScramble(s1 + i, s2, n - i)) {
                return true;
            }
        }
        return false;
    }
};
