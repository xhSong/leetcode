class Solution {
public:
    int searchInsert(int A[], int n, int target) {
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