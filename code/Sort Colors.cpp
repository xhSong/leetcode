class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0};
        for (int i = 0; i < n; ++i) {
            ++ count[A[i]];
        }
        for (int i = 0, k = 0; i < 3; ++i) {
            for (int j = 0; j < count[i]; ++j, ++k) {
                A[k] = i;
            }
        }
    }
};