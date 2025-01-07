class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j)
                    grid[i][j] = 1 - grid[i][j];
            }
        }
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                cnt += grid[i][j];
            }
            if (cnt < (m + 1) / 2) {
                for (int i = 0; i < m; ++i)
                    grid[i][j] = 1 - grid[i][j];
            }
        }
        
        int res = 0;
        for (auto& row : grid) {
            int num = 0;
            for (int j = 0; j < n; ++j)
                num = (num << 1) | row[j];
            res += num;
        }
        return res;
    }
};
