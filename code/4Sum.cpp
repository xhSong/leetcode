class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > ans;
        if (n < 4) return ans;
        vector<int> next(n, n), pre(n, -1);
        sort(num.begin(), num.end());
        for (int i = n - 2; i >= 0; --i) {
            if (num[i] == num[i + 1]) {
                next[i] = next[i + 1];
            } else {
                next[i] = i + 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (num[i] == num[i - 1]) {
                pre[i] = pre[i - 1];
            } else {
                pre[i] = i - 1;
            }
        }
        for (int i = 0; i < n; i = next[i]) {
            for (int j = i + 1; j < n; j = next[j]) {
                int p = j + 1, q = n - 1;
                while (p < q) {
                    while (p < q && num[i] + num[j] + num[p] + num[q] != target) {
                        if (num[i] + num[j] + num[p] + num[q] < target) {
                            p = next[p];
                        } else {
                            q = pre[q];
                        }
                    }
                    if (p < q) {
                        ans.push_back(quadruplets(num[i], num[j], num[p], num[q]));
                        p = next[p];
                    }
                }
            }
        }
        return ans;
    }
private:
    vector<int> quadruplets(int a, int b, int c, int d) {
        vector<int> replets;
        replets.push_back(a);
        replets.push_back(b);
        replets.push_back(c);
        replets.push_back(d);
        return replets;
    }
};