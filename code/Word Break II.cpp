class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
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
        vector<string> ans;
        _gen(s, dicts, f, s.size(), "", ans);
        return ans;
    }
private:
    void _gen(const string &s, vector<string> &dicts, vector<bool> &f, int k, string now, vector<string> &ans) {
        if (k == 0) {
            ans.push_back(now);
            return ;
        }
        if (f[k] == false) return ;
        for (int i = 0; i < dicts.size(); ++i) {
            int cutlen = dicts[i].length();
            if (k >= cutlen && s.substr(k - cutlen, cutlen) == dicts[i]) {
                _gen(s, dicts, f, k - cutlen, (now == "" ? dicts[i] + now: dicts[i] + " " + now), ans);
            }
        }
    }
};