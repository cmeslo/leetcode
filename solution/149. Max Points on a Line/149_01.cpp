class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < i; ++j) {
                int cnt = 2;
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2) {
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        int x3 = points[k][0], y3 = points[k][1];
                        if (x1 == x3)
                            ++cnt;
                    }
                } else {
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        int x3 = points[k][0], y3 = points[k][1];
                        if (x1 == x3) continue;
                        if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1))
                            ++cnt;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
