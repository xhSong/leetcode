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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        bool newin = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].end < newInterval.start) {
                ans.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                if (!newin) {
                    ans.push_back(newInterval);
                    newin = true;
                }
                ans.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if (!newin) ans.push_back(newInterval);
        return ans;
    }
};