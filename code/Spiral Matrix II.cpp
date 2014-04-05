int dir[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return ans;
        ans = vector<vector<int> >(n, vector<int>(n, 0));
        DFS(0, n, 0, 0, 0);
        return ans;
    }
private:
    void DFS(int k, int n, int x, int y, int d) {
        if (k == n * n) {
            return ;
        }
        ans[x][y] = k + 1;
        int nx = x + dir[d][0], ny = y + dir[d][1];
        if (!(0 <= nx && nx < n && 0 <= ny && ny < n) || ans[nx][ny]) {
            d = (d + 1) % 4;
            nx = x + dir[d][0], ny = y + dir[d][1];
        }
        DFS(k + 1, n, nx, ny, d);
    }
    vector<vector<int> > ans;
};
