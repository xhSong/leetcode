class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int> > len(n, vector<int> (m + 2));
        for (int j = 0; j < m; ++j) {
            for (int i = n - 1; i >= 0; --i) {
                len[i][j + 1] = (matrix[i][j] == '0'? 0: (i == n - 1? 1: len[i + 1][j + 1] + 1));
            }
        }
        int area = 0;
        for (int k = 0; k < n; ++k) {
            len[k][0] = len[k][m + 1] = -1;
            vector<int> &height = len[k], less(m + 2);
            stack<int> min1, min2;
            min2.push(m + 1);
            for (int i = m; i; --i) {
                while(height[min2.top()] >= height[i]) {
                    min2.pop();
                }
                less[i] = min2.top();
                min2.push(i);
            }
            min1.push(0);
            for (int i = 1; i <= m; ++i) {
                while(height[min1.top()] >= height[i]) {
                    min1.pop();
                }
                area = max(area, height[i] * (less[i] - min1.top() - 1));
                min1.push(i);
            }
        }
        return area;
    }
};