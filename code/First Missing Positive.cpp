class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0) return 1;
        for (int i = 0, temp; i < n; ++i) {
            while(0 <= A[i] && A[i] < n && A[i] != i && A[i] != A[A[i]]) {
                swap(A[i], A[A[i]]);
            }
        }
        for (int i = 1; i < n; ++i) {
            if (A[i] != i) {
                return i;
            }
        }
        return n + (A[0] == n);
    }
private:
    void swap(int &a, int &b) {
        a ^= b ^= a ^= b;
    }
};