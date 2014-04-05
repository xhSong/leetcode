class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        char s[16], n = 0;
        while(x) {
            s[n++] = x % 10;
            x /= 10;
        }
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
};