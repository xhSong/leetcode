class Solution {
public:
    int search(int A[], int n, int target) {
        int pivot = findPivot(A, n), idx;
        if (target >= A[0]) {
            idx = find(A, pivot, target);
            if (idx == pivot || A[idx] != target) {
                idx = -1;
            }
        } else {
            idx = find(A + pivot, n - pivot, target) + pivot;
            if (idx == n || A[idx] != target) {
                idx = -1;
            }
        }
        return idx;
    }
private:
    int findPivot(int A[], int n) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (A[mid] >= A[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    int find(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};