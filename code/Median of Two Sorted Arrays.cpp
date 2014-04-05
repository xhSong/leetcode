
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        double ans = findKth(A, m, B, n, (n + m) / 2 + 1);
        if ((n + m) % 2 == 0) {
            ans = ans * 0.5 + findKth(A, m, B, n, (n + m) / 2) * 0.5;
        }
        return ans;
    }
private:
    int findKth(int A[], int m, int B[], int n, int k) {
        if (n == 0) return A[k - 1];
        if (m == 0) return B[k - 1];
        int mid = (m - 1) / 2;
        int pos = lower_bound(B, B + n, A[mid]) - B;
        if (mid + 1 + pos > k) {
            return findKth(A, mid, B, pos, k);
        }
        if (mid + 1 + pos < k) {
            return findKth(A + mid + 1, m - mid - 1, B + pos, n - pos, k - mid - 1 - pos);
        }
        return A[mid];
    }
};
