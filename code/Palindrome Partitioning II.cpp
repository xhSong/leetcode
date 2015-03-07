class Solution {
public:
    int minCut(string s) {
        int n = int(s.size());
        list<int> pivot;
        vector<int> f(s.size() + 1);
        for (int i = 0; i < n; ++i) {
            f[i + 1] = f[i] + 1;
            for (auto it = pivot.begin(); it != pivot.end();) {
                if ((*it - i) >= 0 && s[*it - i] == s[i]) {
                    f[i + 1] = min(f[i + 1], f[*it - i] + 1);
                    ++ it;
                } else {
                    auto pre = it ++;
                    pivot.erase(pre);
                }
            }
            pivot.push_back(i * 2);
            pivot.push_back(i * 2 + 1);
        }
        return f[s.size()] - 1;
    }
};
