class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int lastlen = 0;
        for(int i = 0; s[i]; ++i) {
            if (s[i] != ' ') {
                int p = i + 1;
                while (s[p] && s[p] != ' ') {
                    ++ p;
                }
                lastlen = p - i;
                i = p - 1;
            }
        }
        return lastlen;
    }
};

