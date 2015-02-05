class Solution {
public:
    int findMin(const vector<int>& num) {
        int left = 0, right = int(num.size()) - 1;
        while (left <= right) {
            if (num[left] <= num[right]) return num[left];
            int mid = (left + right) / 2;
            if (num[left] <= num[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};