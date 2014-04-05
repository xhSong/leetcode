class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int s1[n], top1 = 0, s2[n], top2 = 0, area = 0;
        for(int i = 0; i < n; ++i) {
            if (top1 == 0 || height[s1[top1 - 1]] < height[i]) {
                s1[top1++] = i;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (top2 == 0 || height[s2[top2 - 1]] < height[i]) {
                s2[top2++] = i;
            }
        }
        int p1 = 0, p2 = 0;
        while(p1 < top1 && p2 < top2 && s1[p1] < s2[p2]) {
            int newarea = min(height[s1[p1]], height[s2[p2]]) * (s2[p2] - s1[p1]);
            area = max(area, newarea);
            if (height[s1[p1]] < height[s2[p2]]) {
                ++ p1;
            } else {
                ++ p2;
            }
        }
        return area;
    }
};