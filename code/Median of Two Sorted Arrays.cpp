class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((n + m) % 2 == 0) {
            return .5 * findKth(A, m, B, n, (n + m) / 2 - 1) +
            .5 * findKth(A, m, B, n, (n + m) / 2);
        }
        return findKth(A, m, B, n, (n + m) / 2);
    }
private:
    int findKth(int A[], int m, int B[], int n, int k) {
        if (n == 0) return A[k];
        if (m == 0) return B[k];
        int posa = m * k / (n + m), posb = n * k / (n + m);
        if (A[posa] < B[posb]) {
            if (posa + posb == k) {
                return findKth(A + posa, m - posa, B, posb, k - posa);
            }
            return findKth(A + posa + 1, m - posa - 1, B, posb + 1, k - posa - 1);
        }
        if (A[posa] > B[posb]) {
            if (posa + posb == k) {
                return findKth(A, posa, B + posb, n - posb, k - posb);
            }
            return findKth(A, posa + 1, B + posb + 1, n - posb - 1, k - posb - 1);
        }
        return A[posa];
    }
};
