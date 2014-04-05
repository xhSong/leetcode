class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int area = 0, n = height.size();
        int h[n + 2];
        for (int i = 1; i <= n; ++i) {
            h[i] = height[i - 1];
        }
        h[0] = h[n + 1] = -1;
        
        vector<int> less(n + 2);
        stack<int> min1, min2;
        min2.push(n + 1);
        for (int i = n; i; --i) {
            while(h[min2.top()] >= h[i]) {
                min2.pop();
            }
            less[i] = min2.top();
            min2.push(i);
        }
        min1.push(0);
        for (int i = 1; i <= n; ++i) {
            while(h[min1.top()] >= h[i]) {
                min1.pop();
            }
            area = max(area, h[i] * (less[i] - min1.top() - 1));
            min1.push(i);
        }
        return area;
    }
};