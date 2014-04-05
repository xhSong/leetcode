class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int> > f(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (obstacleGrid[i][j] == 0) {
                if (i && j) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                } else if (i && !j) {
                    f[i][j] = f[i - 1][j];
                } else if (!i && j) {
                    f[i][j] = f[i][j - 1];
                } else {
                    f[i][j] = 1;
                }
            }
        }
        return f[n - 1][m - 1];
    }
};