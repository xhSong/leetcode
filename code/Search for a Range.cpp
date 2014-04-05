class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector <int> ans;
        int begin = findBegin(A, n, target);
        int end = findEnd(A, n, target);
        if (begin <= end) {
            ans.push_back(begin);
            ans.push_back(end);
        } else {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
private:
    int findBegin(int A[], int n, int target) {
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
    
    int findEnd(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (A[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};