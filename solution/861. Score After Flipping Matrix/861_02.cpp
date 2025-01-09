class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int res = (1 << (n - 1)) * m;
        for (int j = 1; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i)
                cnt += grid[i][j] == grid[i][0];
            res += max(cnt, m - cnt) * (1 << (n - j - 1));
        }
        return res;
    }
};
