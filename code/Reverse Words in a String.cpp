class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length();
        reverse(s);
        for (int i = 0; i < n; ++i) {
            if (isalpha(s[i])) {
                int p = i + 1;
                while (p < n && isalpha(s[p])) ++p;
                reverse(s, i, p - i);
                i = p;
            }
        }
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ' || s[i] == ' ' && m && s[m - 1] != ' ') {
                s[m ++] = s[i];
            }
        }
        if (s[m - 1] == ' ') -- m;
        s.resize(m);
    }
private:
    bool isalpha(char c) {
        return c != ' ';
    }
    void reverse(string &s, int start = 0, int len = INT_MAX) {
        len = std::min(len, int(s.length()) - start);
        for (int i = 0, p = start, q = start + len - 1; i < len / 2; ++i, ++p, --q) {
            s[p] ^= s[q] ^= s[p] ^= s[q];
        }
    }
};