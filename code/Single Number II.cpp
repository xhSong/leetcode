class Solution {
typedef long long LL;
public:
    int singleNumber(int A[], int n) {
        LL ans = 0, x;
        for (int i = 0; i < n; ++i) {
            x = A[i];
            ans = xor3(ans, abs(x));
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == ans) {
                ++ cnt;
            }
        }
        return cnt == 1? ans: -ans;
    }
private:
    LL xor3(LL x, LL y) {
        if (x == 0 || y == 0) {
            return x ^ y;
        }
        return xor3(x / 3, y / 3) * 3 + (x % 3 + y % 3) % 3;
    }
};