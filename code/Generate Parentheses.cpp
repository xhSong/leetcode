class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n <= 0) return ans;
        vector<vector<string> > ansSet(n + 1);
        ansSet[0].push_back("");
        for (int k = 1; k <= n; ++k) {
            for (int i = 0; i < ansSet[k - 1].size(); ++i) {
                ansSet[k].push_back("(" + ansSet[k - 1][i] + ")");
            }
            for (int i = 1; i < k; ++i) {
                for (int p = 0; p < ansSet[i - 1].size(); ++p) {
                    for (int q = 0; q < ansSet[k - i].size(); ++q) {
                        ansSet[k].push_back("(" + ansSet[i - 1][p] + ")" + ansSet[k - i][q]);
                    }
                }
            }
        }
        return ansSet[n];
    }
};