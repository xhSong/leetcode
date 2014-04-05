class Solution {
public:
    int divide(int dividend, int divisor) {
        long long remind, d1 = dividend, d2 = divisor;
        if (d2 == 0) return 0;
        if (d1 < 0 && d2 < 0) {
            return _divide(-d1, -d2, remind);
        }
        if (d1 < 0 && d2 > 0) {
            return -_divide(-d1, d2, remind);
        }
        if (d1 >= 0 && d2 < 0) {
            return -_divide(d1, -d2, remind);
        }
        if (d1 >= 0 && d2 > 0) {
            return _divide(d1, d2, remind);
        }
    }
private:
    long long _divide(long long dividend, long long divisor, long long &remind) {
        if (dividend < divisor) {
            remind = dividend;
            return 0;
        }
        long long ans = _divide(dividend >> 1, divisor, remind) << 1;
        remind = (remind << 1) | (dividend & 1);
        if (remind >= divisor) {
            remind -= divisor;
            ++ ans;
        }
        return ans;
    }
};