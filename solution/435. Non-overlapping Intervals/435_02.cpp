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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return 0;
        std::sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.end < b.end;
        });
        
        int count = 0, last = 0, n = intervals.size();
        for (int i = 1; i < n; ++i) {
            if (intervals[last].end > intervals[i].start) {
                count++;
            } else {
                last = i;
            }
        }
        return count;
    }
};

int main() {
    vector<Interval> intervals;
    // intervals.push_back(Interval(1, 100)); // Expected: 2
    // intervals.push_back(Interval(11, 22));
    // intervals.push_back(Interval(1, 11));
    // intervals.push_back(Interval(2, 12));
    
    // intervals.push_back(Interval(1, 2)); // Expected: 1
    // intervals.push_back(Interval(2, 3));
    // intervals.push_back(Interval(3, 4));
    // intervals.push_back(Interval(1, 3));
    
    // intervals.push_back(Interval(0, 1)); // Expected: 0
    // intervals.push_back(Interval(3, 4));
    // intervals.push_back(Interval(1, 2));
    
    intervals.push_back(Interval(0, 2)); // Expected: 2
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 4));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(4, 6));
    cout << Solution().eraseOverlapIntervals(intervals) << endl;
}
