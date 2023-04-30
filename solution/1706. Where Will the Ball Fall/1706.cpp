class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int x1 = i;
            for (int y = 0; y < m; ++y) {
                int x2 = x1 + grid[y][x1];
                if (x2 < 0 || x2 >= n || grid[y][x1] != grid[y][x2]) {
                    x1 = -1;
                    break;
                }
                x1 = x2;
            }
            res[i] = x1;
        }
        return res;
    }
};
