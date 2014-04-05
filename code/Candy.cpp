class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> c(ratings.size(), 1);
        for(int i = 1; i < c.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                c[i] = c[i - 1] + 1;
            }
        }
        for (int i = c.size() - 1; i; --i) {
            if (ratings[i - 1] > ratings[i]) {
                c[i - 1] = max(c[i - 1], c[i] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < c.size(); ++i) {
            ans += c[i];
        }
        return ans;
    }
};