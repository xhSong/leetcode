class Solution {
public:
    int uniquePaths(int m, int n) {
        return C(n + m -2, n - 1);
    }
private:
    int C(int n, int m) {
        m = min(m, n - m);
        long long ans = 1;
        for (int i = 1; i <= m; ++i) {
            ans = ans * (n - i + 1) / i;
        }
        return ans;
    }
};