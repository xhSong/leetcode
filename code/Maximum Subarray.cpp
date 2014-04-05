class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) return 0;
        int ans = A[0], sum = A[0];
        for (int i = 1; i < n; ++i) {
            sum = max(sum, 0) + A[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};