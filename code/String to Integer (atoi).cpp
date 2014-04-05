class Solution {
public:
    int atoi(const char *str) {
        long long ans = 0;
        int sign = 1;
        char *p = (char *)str;
        while (*p == ' ' || *p == '\t' || *p == '\n') ++p;
        if (*p == '-') {
            sign = -1;
            ++p;
        } else if (*p == '+') {
            ++p;
        }
        while (*p && '0' <= *p && *p <= '9') {
            ans = ans * 10 + (*p++ - '0');
            if (ans >= 2147483648) {
                return sign == 1? 2147483647: -2147483648;
            }
        }
        return ans * sign;
    }
};