class Solution {
public:
    char *strStr(char *s, char *t) {
        int n = strlen(t);
        if (n == 0) return s;
        int next[n], pos = 0;
        next[0] = pos;
        for (int i = 1; i < n; ++i) {
            while(pos && t[next[pos]] != t[i]) {
                pos = next[pos - 1];
            }
            next[i] = pos = pos + (t[pos] == t[i]);
        }
        pos = 0;
        for (int i = 0; s[i]; ++i) {
            while (pos && t[pos] != s[i]) {
                pos = next[pos - 1];
            }
            pos += t[pos] == s[i];
            if (pos == n) return s + i - n + 1;
        }
        return NULL;
    }
};
