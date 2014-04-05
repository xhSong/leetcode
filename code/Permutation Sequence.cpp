class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> select(n + 1, false);
        vector<int> fac(n + 1, 1);
        string s;
        for (int i = 2; i <= n; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        -- k;
        for (int i = n - 1; i >= 0; --i) {
            s.push_back(_get(select, k / fac[i]) + '0');
            k %= fac[i];
        }
        return s;
    }
private:
    int _get(vector<bool> &select, int k) {
        int cnt = 0;
        for (int i = 1; i < select.size(); ++i) {
            if (select[i] == false) {
                ++ cnt;
            }
            if (cnt == k + 1) {
                select[i] = true;
                return i;
            }
        }
        return -1;
    }
};
