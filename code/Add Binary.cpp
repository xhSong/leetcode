class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        int c = 0;
        for (int i = 0; i < a.size() || i < b.size(); ++i) {
            if (i < a.size()) {
                c += a[a.size() - 1 - i] - '0';
            }
            if (i < b.size()) {
                c += b[b.size() - 1 - i] - '0';
            }
            sum.push_back(c % 2 + '0');
            c /= 2;
        }
        if (c) {
            sum.push_back('1');
        }
        return string(sum.rbegin(), sum.rend());
    }
};