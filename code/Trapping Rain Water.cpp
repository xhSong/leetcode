class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        int stk[n], top = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            while (top && A[stk[top - 1]] <= A[i]) {
                if (top >= 2) {
                    ans += (min(A[stk[top - 2]], A[i])  - A[stk[top - 1]]) * (i - stk[top - 2] - 1);
                }
                -- top;
            }
            stk[top++] = i;
        }
        return ans;
    }
};