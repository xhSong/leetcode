class Solution {
public:
    int reverse(int x) {
        long long y = x;
        if (y >= 0) {
            return _reverse(y);
        }
        return - _reverse(-y);
    }
private:
    long long _reverse(long long x) {
        int a[32], n = 0;
        long long ans = 0;
        while (x) {
            a[n++] = x % 10;
            x /= 10;
        }
        for (int i = 0; i < n; ++i) {
            ans = ans * 10 + a[i];
        }
        return ans;
    }
};