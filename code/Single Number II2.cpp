class Solution {
typedef long long LL;
public:
    int singleNumber(int A[], int n) {
        return single((unsigned*)(A), n);
    }

private:
    int single(unsigned A[], int n) {
        if (n == 1) return A[0];
        unsigned remind = 0;
        for (int i = 0; i < n; ++i) {
            remind = (remind + A[i] % 3) % 3;
        }
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] % 3 == remind) {
                A[m++] = A[i] / 3;
            }
        }
        return single(A, m) * 3 + remind;
    }
};
