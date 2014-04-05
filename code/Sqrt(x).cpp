class Solution {
public:
    int sqrt(int x) {
        long long left = 0, right = x, mid;
        while(left <= right) {
            mid = (left + right) / 2;
            if (mid * mid <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};