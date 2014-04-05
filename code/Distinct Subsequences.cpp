class Solution {
public:
    int numDistinct(string S, string T) {
        vector<vector<int> > f(T.size() + 1, vector<int>(S.size() + 1, 0));
        for (int j = 0; j <= S.size(); ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i <= T.size(); ++i) {
            for (int j = 1; j <= S.size(); ++j) {
                f[i][j] = f[i][j - 1];
                if (T[i - 1] == S[j - 1]) {
                    f[i][j] += f[i - 1][j - 1];
                }
            }
        }
        return f[T.size()][S.size()];
    }
};