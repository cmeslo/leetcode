class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& C) {
        int x0 = C[0][0], y0 = C[0][1];
        int x1 = C[1][0], y1 = C[1][1];
        int dy = y1 - y0, dx = x1 - x0;
        for (auto& c : C) {
            int x = c[0], y = c[1];
            if (dy * (x - x0) != (y - y0) * dx)
                return false;
        }
        return true;
    }
};

// (y2 - y1) / (x2 - x1) = (y3 - y1) / (x3 - x1)
// (y2 - y1) * (x3 - x1) = (y3 - y1) * (x2 - x1)
// dy * (xi - x1) = (yi - y1) * dx
