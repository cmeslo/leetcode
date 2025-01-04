class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                int mx = 0;
                for (int y = i; y < i + 3; ++y) {
                    for (int x = j; x < j + 3; ++x) {
                        mx = max(mx, grid[y][x]);
                    }
                }
                res[i][j] = mx;
            }
        }
        return res;
    }
};