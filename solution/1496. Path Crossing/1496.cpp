class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> P;
        int x = 0, y = 0;
        P.insert({x, y});
        for (char& dir : path) {
            if (dir == 'N')
                ++y;
            else if (dir == 'S')
                --y;
            else if (dir == 'E')
                ++x;
            else if (dir == 'W')
                --x;
            if (P.count({x, y}))
                return true;
            P.insert({x, y});
        }
        return false;
    }
};
