class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        ans.clear();
        now.clear();
        _DFS(0, n, 0, 0, 0);
        return ans;
    }
private:
    void _DFS(int k, int n, int left, int right, int up) {
        if (k == n) {
            _gen(n);
        }
        for (int i = 0; i < n; ++i) {
            if (!(left & 1<<i) && !(right & 1<<i) && !(up & 1<<i)) {
                now.push_back(i);
                _DFS(k + 1, n, (left | 1<<i) << 1, (right | 1<<i) >> 1, (up | 1<<i));
                now.pop_back();
            }
        }
    }
    void _gen(int n) {
        vector<string> solve;
        string line(n, '.');
        for (int i = 0; i < n; ++i) {
            line[now[i]] = 'Q';
            solve.push_back(line);
            line[now[i]] = '.';
        }
        ans.push_back(solve);
    }
    vector<vector<string> > ans;
    vector<int> now;
};