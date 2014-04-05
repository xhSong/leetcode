class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) row[i][j] = col[i][j] = blk[i][j] = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int c = board[i][j] - '1';
                    row[i][c] = col[j][c] = blk[i / 3 * 3 + j / 3][c] = true;
                }
            }
        }
        solve(board, 0);
    }
    
private:
    bool solve(vector<vector<char> > &board, int k) {
        if (k == 81) return true;
        int x = k / 9, y = k % 9;
        if (board[x][y] != '.') return solve(board, k + 1);
        for (int i = 0; i < 9; ++i) {
            if (!(row[x][i] || col[y][i] || blk[x / 3 * 3 + y / 3][i])) {
                row[x][i] = col[y][i] = blk[x / 3 * 3 + y / 3][i] = true;
                board[x][y] = i + '1';
                if(solve(board, k + 1)) return true;
                board[x][y] = '.';
                row[x][i] = col[y][i] = blk[x / 3 * 3 + y / 3][i] = false;
            }
        }
        return false;
    }
    bool row[9][9], col[9][9], blk[9][9];
};