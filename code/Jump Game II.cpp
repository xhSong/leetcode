class Solution {
public:
    int jump(int A[], int n) {
        priority_queue<Point> que;
        Point last;
        que.push(Point());
        for (int i = 0; i < n; ++i) {
            last = que.top();
            while (last.x < i) {
                que.pop();
                last = que.top();
            }
            if (i == n - 1) return last.value;
            que.push(Point(i + A[i], last.value + 1));
        }
    }
private:
    struct Point {
        int x, value;
        Point(): x(0), value(0){};
        Point(int x, int value):x(x), value(value){};
        bool operator<(const Point &p) const {
            return value > p.value;
        }
    };
};