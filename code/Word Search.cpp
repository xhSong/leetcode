int dir[][2] = {0, 1, 0, -1, 1, 0, -1, 0};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) return false;
        int n = board.size(), m = board[0].size();
        visted = vector<vector<bool> >(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (DFS(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return  false;
    }
    
private:
    bool DFS(int x, int y, vector<vector<char> > &board, string &word, int k) {
        if (k == word.size()) return true;
        int n = board.size(), m = board[0].size();
        if (!(0 <= x && x < n && 0 <= y && y < m && word[k] == board[x][y] && !visted[x][y])) {
            return false;
        }
        visted[x][y] = true;
        bool found = false;
        for (int i = 0; i < 4; ++i) {
            if (found = DFS(x + dir[i][0], y + dir[i][1], board, word, k + 1)) {
                break;
            }
        }
        visted[x][y] = false;
        return found;
    }
    vector<vector<bool> > visted;
};