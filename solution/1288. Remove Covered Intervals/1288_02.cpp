class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && b[1] < a[1]);
        });
        
        int ans = 0, end = 0;
        for (const auto& interval : intervals) {
            if (end < interval[1]) {
                ++ans;
                end = interval[1];
            }
        }
        
        return ans;
    }
};
