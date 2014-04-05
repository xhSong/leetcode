/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval node(intervals[0].start, intervals[0].end);
        for (int i = 1; i < intervals.size(); ++i) {
            if (node.end < intervals[i].start) {
                ans.push_back(node);
                node = intervals[i];
            } else {
                node.end = max(node.end, intervals[i].end);
            }
        }
        ans.push_back(node);
        return ans;
    }
private:
    static bool cmp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};