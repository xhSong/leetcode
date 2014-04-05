class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.size() + 1, false);
        vector<string> dicts;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            dicts.push_back(*it);
        }
        f[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < dicts.size(); ++j) {
                int cutlen = dicts[j].length();
                if (i >= cutlen && s.substr(i - cutlen, cutlen) == dicts[j]) {
                    f[i] = f[i] | f[i - cutlen];
                }
            }
        }
        return f[s.size()];
    }
};