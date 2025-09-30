class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> O;
        for (auto& o : obstacles)
            O.insert({o[0], o[1]});
        
        int res = 0;
        int dy = 1, dx = 0;
        int y = 0, x = 0;
        for (auto& k : commands) {
            if (k > 0) {
                while (k--) {
                    if (O.count({x + dx, y + dy})) continue;
                    x += dx;
                    y += dy;
                }
            } else if (k == -2) {
                if (dx == 0 && dy == 1)
                    dx = -1, dy = 0;
                else if (dx == -1 && dy == 0)
                    dx = 0, dy = -1;
                else if (dx == 0 && dy == -1)
                    dx = 1, dy = 0;
                else
                    dx = 0, dy = 1;
            } else if (k == -1) {
                if (dx == 0 && dy == 1)
                    dx = 1, dy = 0;
                else if (dx == 1 && dy == 0)
                    dx = 0, dy = -1;
                else if (dx == 0 && dy == -1)
                    dx = -1, dy = 0;
                else
                    dx = 0, dy = 1;
            }
            res = max(res, x * x + y * y);
        }
        return res;
    }
};

// -90 deg:
//  0, 1 -> -1, 0 -> 0, -1 ->  1, 0 ->  0, 1
