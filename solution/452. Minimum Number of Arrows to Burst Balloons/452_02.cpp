class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const auto& a, const auto& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });
        
        int n = points.size();
        int arrows = 0;
        
        for (int i = 0; i < n; ++i) {
            int end = points[i][1];
            while (i + 1 < n && points[i + 1][0] <= end) {
                end = min(end, points[i + 1][1]);
                ++i;
            }
            ++arrows;
        }
        
        return arrows;
    }
};
