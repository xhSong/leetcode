class Solution {
public:
    int singleNumber(int A[], int n) {
        int cnt0 = ~0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            int cnt2_ = cnt2;
            cnt2 = (cnt2 & ~A[i]) | (cnt1 & A[i]);
            cnt1 = (cnt1 & ~A[i]) | (cnt0 & A[i]);
            cnt0 = (cnt0 & ~A[i]) | (cnt2_ & A[i]);
        }
        return cnt1;
    }
};