class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int m = 2;
        for (int i = 2; i < n; ++i) {
            if (A[m - 2] != A[i]) {
                A[m++] = A[i];
            }
        }
        return m;
    }
};