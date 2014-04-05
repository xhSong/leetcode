class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > row(9, vector<bool> (9, false)), col(9, vector<bool> (9, false)), blk(9, vector<bool> (9, false));
        //bool row[9][9] = {false};
        //bool col[9][9] = {false};
        //bool blk[9][9] = {false};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int c = board[i][j] - '1';
                    if (row[i][c] || col[j][c] || blk[i / 3 * 3 + j / 3][c]) {
                        return false;
                    }
                    row[i][c] = col[j][c] = blk[i / 3 * 3 + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};