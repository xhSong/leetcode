class Solution {
public:
    int findMin(const vector<int>& num) {
        return findMin(num, 0, int(num.size()) - 1);
    }
private:
    int findMin(const vector<int>& num, int left, int right) {
        if (left == right) return num[left];
        int mid = (left + right) / 2;
        if (num[left] > num[mid] || num[mid] < num[right]) return findMin(num, left, mid);
        if (num[mid] > num[right]) return findMin(num, mid + 1, right);
        return min(findMin(num, left, mid), findMin(num, mid + 1, right));
    }
};
