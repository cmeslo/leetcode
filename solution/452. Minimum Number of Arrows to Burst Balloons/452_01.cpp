class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int res = 1;
        int mx = points[0][1];
        for (auto& p : points) {
            if (p[0] > mx) {
                ++res;
                mx = p[1];
            }
        }
        return res;
    }
};
