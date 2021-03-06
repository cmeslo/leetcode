class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && b[1] < a[1]);
        });
        
        int covered = 0;
        int start = 0, end = 0;
        for (const auto& interval : intervals) {
            if (start <= interval[0] && interval[1] <= end)
                ++covered;
            else
                start = interval[0], end = interval[1];
        }
        
        return intervals.size() - covered;
    }
};
