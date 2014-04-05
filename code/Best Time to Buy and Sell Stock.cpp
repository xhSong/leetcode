class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int minprice = prices[0], ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            ans = max(ans, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return ans;
    }
};