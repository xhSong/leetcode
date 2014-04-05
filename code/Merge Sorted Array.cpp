class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for (int i = m + n - 1; i >= 0; --i) {
            int k;
            if (m && n) {
                if (A[m - 1] >= B[n - 1]) {
                    k = A[--m];
                } else {
                    k = B[--n];
                }
            } else if (m && !n) {
                k = A[--m];
            } else if (!m && n) {
                k = B[--n];
            }
            A[i] = k;
        }
    }
};