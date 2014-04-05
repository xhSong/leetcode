class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int f[prices.size()][2];
        f[0][0] = 0, f[0][1] = -prices[0];;
        for (int i = 1; i < prices.size(); ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i]);
            f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i]);
        }
        return f[prices.size() - 1][0];
    }
};