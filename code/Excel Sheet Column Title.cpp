class Solution {
public:
    string convertToTitle(int n) {
        string result;
        for (; n; n = (n - 1) / 26) {
            result += char('A' + (n - 1) % 26);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};