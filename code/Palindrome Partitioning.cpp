class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool> > pali(s.size(), vector<bool> (s.size() + 1, false));
        for (int i = 0; i < n; ++i) {
            pali[i][i] = pali[i][i + 1] = true;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len;
                if (s[i] == s[j - 1] && pali[i + 1][j - 1]) {
                    pali[i][j] = true;
                }
            }
        }
        vector<vector<string> > ans;
        vector<string> now;
        _gen(s, 0, pali, ans, now);
        return ans;
    }
private:
    void _gen(string &s, int k, vector<vector<bool> > &pali, vector<vector<string>> &ans, vector<string> &now) {
        if (k == s.size()) {
            ans.push_back(now);
            return ;
        }
        for (int i = k + 1; i <= s.size(); ++i) {
            if (pali[k][i]) {
                now.push_back(s.substr(k, i - k));
                _gen(s, i, pali, ans, now);
                now.pop_back();
            }
        }
    }
};