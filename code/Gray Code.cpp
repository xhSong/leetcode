class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if (n <= 0) return ans;
        ans.push_back(1);
        for (int k = 2; k <= n; ++k) {
            vector<int> extended;
            for (int i = 0; i < ans.size(); ++i) {
                if (i % 2 == 0) {
                    extended.push_back(ans[i] << 1);
                    extended.push_back(ans[i] << 1 | 1);
                } else {
                    extended.push_back(ans[i] << 1 | 1);
                    extended.push_back(ans[i] << 1);
                }
            }
            ans = extended;
        } 
        return ans;
    }
};