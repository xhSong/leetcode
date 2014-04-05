class Solution {
public:
    int totalNQueens(int n) {
        return _DFS(0, n, 0, 0, 0);
    }
private:
    int _DFS(int k, int n, int left, int right, int up) {
        if (k == n) {
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!(left & 1<<i) && !(right & 1<<i) && !(up & 1<<i)) {
                ans += _DFS(k + 1, n, (left | 1<<i) << 1, (right | 1<<i) >> 1, (up | 1<<i));
            }
        }
        return ans;
    }
};