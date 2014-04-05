class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) return 0;
        int ans = num[0] + num[1] + num[2], temp;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            int j = i + 1, k = num.size() - 1;
            while(j < k) {
                while (j < k && num[i] + num[j] + num[k] >= target) {
                    if (abs(ans - target) > abs((temp = num[i] + num[j] + num[k]) - target)) {
                        ans = temp;
                    }
                    -- k;
                }
                while (j < k && num[i] + num[j] + num[k] <= target) {
                    if (abs(ans - target) > abs((temp = num[i] + num[j] + num[k]) - target)) {
                        ans = temp;
                    }
                    ++ j;
                }
            }
        }
        return ans;
    }
};