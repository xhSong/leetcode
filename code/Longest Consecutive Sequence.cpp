class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0) return 0;
        sort(num.begin(), num.end());
        num.resize(unique(num.begin(), num.end()) - num.begin());
        int res = 1, cnt = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == num[i - 1] + 1) {
                ++ cnt;
            } else {
                cnt = 1;
            }
            res = max(res, cnt);
        }
        return res;        
    }
};
