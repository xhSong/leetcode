class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = int(num.size());
        if (n <= 1) return 0;
        int maxvalue = *(max_element(num.begin(), num.end()));
        int minvalue = *(min_element(num.begin(), num.end()));
        vector<pair<int, int>> interval(n, make_pair(maxvalue, -1));
        int valsize = (maxvalue - minvalue + 1) / int(num.size()) + 1;
        for (int i = 0; i < n; ++i) {
            int idx = (num[i] - minvalue) / valsize;
            interval[idx].first = min(interval[idx].first, num[i]);
            interval[idx].second = max(interval[idx].second, num[i]);
        }
        int result = 0, x = interval[0].first;
        for (int i = 0; i < n; ++i) {
            if (interval[i].second != -1) {
                result = max(result, interval[i].first - x);
                x = interval[i].second;
            }
        }
        return result;
    }
};