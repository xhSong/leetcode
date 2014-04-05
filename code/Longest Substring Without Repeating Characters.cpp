class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(256, 0);
        int ans = 0;
        for (int i = 0, begin = 0; i < s.size(); ++i) {
            ++ cnt[s[i]];
            while (cnt[s[i]] >= 2) {
                -- cnt[s[begin++]];
            }
            ans = max(ans, i - begin + 1);
        }
        return ans;
    }
};
