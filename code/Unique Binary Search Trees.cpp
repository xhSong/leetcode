class Solution {
public:
    int numTrees(int n) {
        return C(2 * n, n) / (n + 1);
    }
private:
    long long C(int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= m; ++i) {
            ans = ans * (n - i + 1) / i;
        }
        return ans;
    }
};