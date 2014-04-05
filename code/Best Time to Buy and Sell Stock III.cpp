class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int> > f(n + 1, vector<int>(5, 0));
        f[0][1] = f[0][3] = -prices[0];
        for (int i = 1; i <= prices.size(); ++i) {
            f[i][0] = f[i - 1][0];
            f[i][1] = max(f[i][0] - prices[i - 1], f[i - 1][1]);
            f[i][2] = max(f[i][1] + prices[i - 1], f[i - 1][2]);
            f[i][3] = max(f[i][2] - prices[i - 1], f[i - 1][3]);
            f[i][4] = max(f[i][3] + prices[i - 1], f[i - 1][4]);
        }
        return f[n][4];
    }
};
