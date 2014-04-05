class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size(), left = 0, right = 0;
        vector<int> leftgas(n * 2), que(n * 2);
        leftgas[0] = 0;
        for (int i = 1; i < leftgas.size(); ++i) {
            leftgas[i] = leftgas[i - 1] + gas[(i - 1) % n] - cost[(i - 1) % n];
        }
        for (int i = 0; i < n; ++i) {
            while (left < right && leftgas[que[right - 1]] >= leftgas[i]) {
                -- right;
            }
            que[right++] = i;
        }
        for (int i = n; i < leftgas.size(); ++i) {
            if (que[left] == i - n) ++left;
            while (left < right && leftgas[que[right - 1]] >= leftgas[i]) {
                -- right;
            }
            que[right++] = i;
            if (leftgas[que[left]] >= leftgas[i - n]) {
                return i - n;
            }
        }
        return -1;
    }
};s