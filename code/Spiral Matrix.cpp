int dir[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        ans.clear();
        if (matrix.size() == 0) return ans;
        visted = vector<vector<bool> >(matrix.size(), vector<bool>(matrix[0].size(), false));
        _gen(matrix, 0, 0, 0);
        return ans;
    }
private:
    void _gen(vector<vector<int> > &matrix, int x, int y, int d) {
        int n = matrix.size(), m = matrix[0].size();
        ans.push_back(matrix[x][y]);
        visted[x][y] = true;
        if (ans.size() == n * m) return ;
        int nx = x + dir[d][0], ny = y + dir[d][1];
        if ((0 <= nx && nx < n && 0 <= ny && ny < m) && !visted[nx][ny]) {
            _gen(matrix, nx, ny, d);
        } else {
            d = (d + 1) % 4;
            _gen(matrix, x + dir[d][0], y + dir[d][1], d);
        }
    }
    vector<vector<bool> > visted;
    vector<int> ans;
};