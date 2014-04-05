class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        string ans;
        for (int k = 0; k < strs[0].size(); ++k) {
            bool diff = false;
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].size() <= k || strs[i][k] != strs[0][k]) {
                    diff = true;
                    break;
                }
            }
            if (diff) break;
            ans.push_back(strs[0][k]);
        }
        return ans;
    }
};