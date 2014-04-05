class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n <= 0) return false;
        if (n == 1) return A[0] == target;
        int left = 0, right = n - 1, mid = (left + right) / 2;
        if (A[left] == target || A[right] == target || A[mid] == target) return true;
        if (A[left] < A[mid]) {
            if (A[left] < target && target < A[mid]) {
                return search(A + left + 1, mid - left - 1, target);
            } else {
                return search(A + mid + 1, right - mid - 1, target);
            }
        }
        if (A[mid] < A[right]) {
            if (A[mid] < target && target < A[right]) {
                return search(A + mid + 1, right - mid - 1, target);
            } else {
                return search(A + left + 1, mid - left - 1, target);
            }
        }
        return search(A + left + 1, mid - left - 1, target) || search(A + mid + 1, right - mid - 1, target);
    }
};