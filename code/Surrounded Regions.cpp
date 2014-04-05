class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if (board.size() == 0 || board[0].size() == 0) return ;
        int n = board.size(), m = board[0].size(), dir[][2] = {1, 0, -1, 0, 0, -1, 0, 1};
        
        vector<vector<bool> > visted(n, vector<bool> (m, false));
        for (int i = 0; i < n; ++i) {
            if (!visted[i][0]) {
                DFS(board, visted, i, 0, dir);
            }
            if (!visted[i][m - 1]) {
                DFS(board, visted, i, m - 1, dir);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (!visted[0][i]) {
                DFS(board, visted, 0, i, dir);
            }
            if (!visted[n - 1][i]) {
                DFS(board, visted, n - 1, i, dir);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visted[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void DFS(vector<vector<char> > &board, vector<vector<bool> > &visted, int x, int y, int dir[][2]) {
        int n = board.size(), m = board[0].size();
        if (!(0 <= x && x < n && 0 <= y && y < m)) return ;
        if (board[x][y] == 'X' || visted[x][y]) return;
        visted[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            DFS(board, visted, x + dir[i][0], y + dir[i][1], dir);
        }
    }
};