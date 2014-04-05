class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string keys[] = {" ", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string let = "";
        _gen(digits, 0, ans, let, keys);
        return ans;
    }
private:
    void _gen(string &digits, int k, vector<string> &ans, string &let, string keys[]) {
        if (k >= digits.size()) {
            ans.push_back(let);
            return;
        }
        for (int i = 0; i < keys[digits[k] - '0'].size(); ++i) {
            let.push_back(keys[digits[k] - '0'][i]);
            _gen(digits, k + 1, ans, let, keys);
            let.pop_back();
        }
    }
};