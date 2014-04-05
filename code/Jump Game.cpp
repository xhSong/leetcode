class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1) return true;
        int maxJump = A[0];
        for (int i = 0; i < n; ++i) {
            if (maxJump < i) return false;
            maxJump = max(maxJump, A[i] + i);
        }
        return true;
    }
};