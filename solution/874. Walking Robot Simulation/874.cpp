class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> O;
        for (auto& o : obstacles)
            O.insert({o[0], o[1]});
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int res = 0;
        int y = 0, x = 0, d = 0;
        for (auto& k : commands) {
            if (k > 0) {
                while (k--) {
                    if (O.count({x + dirs[d].first, y + dirs[d].second})) break;
                    x += dirs[d].first;
                    y += dirs[d].second;
                }
            } else if (k == -2) {
                d = (d - 1 + 4) % 4;
            } else if (k == -1) {
                d = (d + 1) % 4;
            }
            res = max(res, x * x + y * y);
        }
        return res;
    }
};
