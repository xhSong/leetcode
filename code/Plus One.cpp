class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            c += digits[i];
            digits[i] = c % 10;
            c /= 10;
        }
        if (c) {
            digits.push_back(0);
            for (int i = digits.size() - 1; i; --i) {
                digits[i] = digits[i - 1];
            }
            digits[0] = c;
        }
        return digits;
    }
};