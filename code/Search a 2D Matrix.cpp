class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (matrix[mid / m][mid % m] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left < n * m && matrix[left / m][left % m] == target;
    }
};