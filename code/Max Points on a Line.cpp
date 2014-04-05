/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int ans = min(2, (int)points.size());
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                ans = max(ans, pointsInLine(points, points[i], points[j]));
            }
        }
        return ans;
    }
    
private:
    int pointsInLine(const vector<Point> &points, const Point &p1, const Point &p2) {
        int count = 0;
        for (int i = 0; i < points.size(); ++i) {
            if (!equal(p1, p2) && inLine(p1, p2, points[i]) || equal(p1, p2) && equal(points[i], p1)) {
                ++ count;
            }
        }
        return count;
    }
    
    bool equal(const Point &p1, const Point &p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    
    bool inLine(const Point &p1, const Point &p2, const Point &p3) {
        return (p2.y - p1.y) * (p3.x - p1.x) == (p2.x - p1.x) * (p3.y - p1.y);
    }
};