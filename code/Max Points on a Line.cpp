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
        if (points.size() <= 2) return points.size();
        int result = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            vector<Point> diff;
            int same = 0;
            for (size_t j = 0; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++ same;
                } else {
                    diff.push_back(Point(points[i].x - points[j].x,
                                         points[i].y - points[j].y));
                }
            }
            sort(diff.begin(), diff.end(), cmp);
            result = max(result, same);
            int counter = 1;
            for (size_t i = 1; i < diff.size(); ++i) {
                if (diff[i].x * diff[i - 1].y == diff[i].y * diff[i - 1].x) {
                    ++ counter;
                } else {
                    counter = 1;
                }
                result = max(result, counter + same);
            }
        }
        return result;
    }
private:
    static bool cmp(const Point& a, const Point& b) {
        return a.x * b.y < a.y * b.x;
    }
};