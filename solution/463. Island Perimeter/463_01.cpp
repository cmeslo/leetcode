class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const vector<int> dirs = {0, -1, 0, 1, 0};
        int m = grid.size(), n = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                for (int k = 0; k < 4; ++k) {
                    int y = i + dirs[k];
                    int x = j + dirs[k + 1];
                    if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == 0) ++ans;
                }
            }
        }
        return ans;
    }
};
