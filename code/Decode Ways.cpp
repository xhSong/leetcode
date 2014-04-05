class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        vector<int> f(s.size() + 1, 0);
        f[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            if ('1' <= s[i] && s[i] <= '9') {
                f[i + 1] += f[i];
            }
            if (i) {
                int p = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (10 <= p && p <= 26) {
                    f[i + 1] += f[i - 1];
                }
            }
        }
        return f[s.size()];
    }
};