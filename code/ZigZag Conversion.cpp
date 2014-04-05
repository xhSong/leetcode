class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        vector<string> row(nRows);
        for (int i = 0; i < s.size(); ++i) {
            int remind = i % (2 * nRows - 2);
            if (remind < nRows) {
                row[remind].push_back(s[i]);
            } else {
                row[2 * nRows - 2 - remind].push_back(s[i]);
            }
        }
        string ans;
        for (int i = 0; i < nRows; ++i) {
            ans += row[i];
        }
        return ans;
    }
};
