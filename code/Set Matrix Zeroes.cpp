class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) return ;
        int n = matrix.size(), m = matrix[0].size();
        vector<bool> row(n, false), col(m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};