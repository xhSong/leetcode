class Solution {
public:
    double pow(double x, int n) {
        long long longn = n;
        if (n < 0) return 1 / _pow(x, -longn);
        return _pow(x, n);
    }
private:
    double _pow(double x, long long n) {
        double ans = 1.0;
        while (n) {
            if (n % 2) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};