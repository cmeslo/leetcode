class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> m;
            int mx_slope = 0, same = 1;
            for (int j = i + 1; j < n; ++j) {
                if (points[i] == points[j]) {
                    ++same;
                } else {
                    mx_slope = max(mx_slope, ++m[getSlope(points[i], points[j])]);
                }
            }
            res = max(res, same + mx_slope);
        }
        return res;
    }

    pair<int, int> getSlope(vector<int>& a, vector<int>& b) {
        int dy = b[1] - a[1];
        int dx = b[0] - a[0];
        if (dy == 0) return {a[1], 0};
        if (dx == 0) return {0, a[0]};
        int g = __gcd(dy, dx);
        return {dy / g, dx / g};
    }
    
    // same as __gcd
    // int gcd(int m, int n) {
    //     return n == 0 ? m : gcd(n, m % n);
    // }
};
