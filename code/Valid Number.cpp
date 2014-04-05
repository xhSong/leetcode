class Solution {
public:
    bool isNumber(const char *s) {
        int left = 0, right = strlen(s) - 1;
        while(left <= right && (s[left] == ' ' || s[left] == '\t' || s[left] == '\n')) {
            ++ left;
        }
        while(left <= right && (s[right] == ' ' || s[right] == '\t' || s[right] == '\n')) {
            -- right;
        }
        if (left > right) return false;
        int cnt_dot = 0, cnt_e = 0, pos_e = 0;
        for (int i = left; i <= right; ++i) {
            if (!('0' <= s[i] && s[i] <= '9')) {
                if (s[i] == '.') {
                    ++ cnt_dot;
                } else if (s[i] == 'e' || s[i] == 'E'){
                    ++ cnt_e;
                    pos_e = i;
                } else if (s[i] != '-' && s[i] != '+'){
                    return false;
                }
            }
        }
        if (cnt_e > 1 || cnt_dot > 1) {
            return false;
        }
        if ((cnt_e && isFloat(s, left, pos_e - 1) && isInt(s, pos_e + 1, right)) || (!cnt_e && isFloat(s, left, right))) {
            return true;
        }
        return false;
    }
private:
    bool isFloat(const char *s, int left, int right) {
        if (left <= right && (s[left] == '-' || s[left] == '+')) {
            ++left;
        }
        if (left > right) return false;
        if (s[left] == '.' && left == right) {
            return false;
        }
        for (int i = left; i <= right; ++i) {
            if (!('0' <= s[i] && s[i] <= '9' || s[i] == '.')) {
                return false;
            }
        }
        return true;
    }
    
    bool isInt(const char *s, int left, int right) {
        if (left <= right && (s[left] == '-' || s[left] == '+')) {
            ++ left;
        }
        if (left > right) return false;
        for (int i = left; i <= right; ++i) {
            if (!('0' <= s[i] && s[i] <= '9')) {
                return false;
            }
        }
        return true;
    }
};
