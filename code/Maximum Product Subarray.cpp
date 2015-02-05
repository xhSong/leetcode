class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0) return 0;
        int maxa = A[0], mina = A[0], maxp = A[0];
        for (int i = 1; i < n; ++i) {
            int maxt = maxa * A[i];
            int mint = mina * A[i];
            maxa = std::max(std::max(maxt, mint), A[i]);
            mina = std::min(std::min(maxt, mint), A[i]);
            maxp = std::max(maxa, maxp);
        }
        return maxp;
    }
};