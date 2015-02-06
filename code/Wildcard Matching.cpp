class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        vector<char *> blk;
        int lenp = strlen(p), lens = strlen(s);
        char cp[lenp + 1], *head = (char *)s, *tail;
        strcpy(cp, p);
        for (int i = 0; i <= lenp; ++i) {
            if (cp[i] == '*') {
                cp[i] = 0;
                if (i == 0) {
                    blk.push_back(cp + i);
                }
            } else {
                if (i == 0 || cp[i - 1] == 0) {
                    blk.push_back(cp + i);
                }
            }
        }
        
        if (blk.size() == 1 && lenp != lens) return false;
        
        tail = head + lens - strlen(blk[blk.size() - 1]);
        if (strStr(head, blk[0]) != head || strStr(tail, blk[blk.size() - 1]) != tail) {
            return false;
        }
        
        for (int i = 0; i < blk.size(); ++i) {
            head = strStr(head, blk[i]);
            if (head == NULL) return false;
            head += strlen(blk[i]);
        }
        return true;
    }
private:
    char *strStr(char *s, char *t) {
        int n = strlen(t);
        if (n == 0) return s;
        int next[n + 1], pos = 0;
        next[0] = pos;
        for (int i = 1; i < n; ++i) {
            while(pos && t[pos] != t[i] && t[i] != '?' && t[pos] != '?') {
                pos = next[pos - 1];
            }
            next[i] = pos = pos + (t[pos] == t[i] || t[pos] == '?' || t[i] == '?');
        }

        pos = 0;
        for (int i = 0; s[i]; ++i) {
            while (pos && t[pos] != '?' && t[pos] != s[i]) {
                pos = next[pos - 1];
            }
            pos += (t[pos] == s[i] || t[pos] == '?');
            if (pos == n) return s + i - n + 1;
        }
        return NULL;
    }
    
};