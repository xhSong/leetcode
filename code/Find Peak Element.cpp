class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left = 0, right = num.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((mid - 1 < left || num[mid - 1] < num[mid]) &&
                (mid + 1 > right || num[mid + 1] < num[mid])) {
                return mid;
            }
            if (mid - 1 >= left && num[mid - 1] > num[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};