class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        map<string, int> cnt;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (cnt.find(s) == cnt.end()) {
                cnt[s] = 1;
            } else {
                ++ cnt[s];
            }
        }
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (cnt[s] >= 2) {
                ans.push_back(strs[i]);
            }
        }
        return ans;
    }
};
