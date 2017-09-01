/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}
class Solution {
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        for(int i=0, j; i<intervals.size(); i=j) {
            j=i;
            int r=intervals[i].end;
            while(j<intervals.size() && intervals[j].start<=r) {
                r=max(r, intervals[j].end);
                ++j;
            }
            res.push_back(Interval(intervals[i].start, r));
        }
        return res;
    }
};
