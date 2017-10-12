class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        std::sort(points.begin(), points.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        
        int res = 1, arrowPos = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if (arrowPos >= points[i].first) continue;
            res++;
            arrowPos = points[i].second;
        }
        return res;
    }
};
