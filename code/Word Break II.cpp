class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> matchable(s.size() + 1, false);
        matchable[s.size()] = true;
        for (int i = int(s.size()) - 1; i >= 0; --i) {
            for (const string &word: dict) {
                if (s.compare(i, word.size(), word) == 0) {
                    matchable[i] = matchable[i] | matchable[i + word.size()];
                }
            }
        }
        vector<string> result;
        gen(s, dict, matchable, 0, "", result);
        return result;
    }
private:
    void gen(string& s, unordered_set<string>& dict, vector<bool>& matchable,
             int k, string now, vector<string>& result) {
        if (k == s.size()) {
            result.push_back(now);
            return ;
        }
        if (k) now += " ";
        for (const string &word: dict) {
            if (s.compare(k, word.size(), word) == 0 && matchable[k + word.size()]) {
                gen(s, dict, matchable, k + word.size(), now + word, result);
            }
        }
    }
};
