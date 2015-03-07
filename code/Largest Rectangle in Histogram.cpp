class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<pair<int, int>> stk;
        int result = 0;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            int left = i;
            while (stk.size() && stk.top().first > height[i]) {
                auto rect = stk.top();
                stk.pop();
                result = max(result, rect.first * (i - rect.second));
                left = rect.second;
            }
            stk.push(make_pair(height[i], left));
        }
        return result;
    }
};
