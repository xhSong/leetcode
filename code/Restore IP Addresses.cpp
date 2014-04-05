class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        now.clear();
        if (s.size() > 12) return ans;
        _DFS(s, 0);
        return ans;
    }
private:
    void _DFS(string &s, int k) {
        if (now.size() == 4 || k == s.size()) {
            if (now.size() == 4 && k == s.size()) {
                ans.push_back(now[0] + "." + now[1] + "." + now[2] + "." + now[3]);
            }
            return ;
        }
        if (s[k] == '0') {
            now.push_back("0");
            _DFS(s, k + 1);
            now.pop_back();
        } else {
            string block = "";
            int value = 0;
            for (int i = k; i < s.size(); ++i) {
                value = value * 10 + s[i] - '0';
                if (value < 256) {
                    block.push_back(s[i]);
                    now.push_back(block);
                    _DFS(s, i + 1);
                    now.pop_back();
                }
            }
        }
        
    }
    vector<string> ans, now;
};