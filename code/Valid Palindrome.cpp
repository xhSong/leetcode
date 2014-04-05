class Solution {
public:
    bool isPalindrome(string s) {
        string charset;
        for (int i = 0; i < s.size(); ++i) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                charset.push_back(s[i] - 'A' + 'a');
            } else if ('a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9') {
                charset.push_back(s[i]);
            }
        }
        for (int i = 0; i < charset.size() / 2; ++i) {
            if (charset[i] != charset[charset.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};