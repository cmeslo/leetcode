class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int rowLen = grid.size();
        int colLen = grid[0].size();

        for (int i = 0; i < rowLen; ++i) {
            for (int j = 0; j < colLen; ++j) {
                if (grid[i][j] == 0) continue;
                res += 4;
                if (j > 0 && grid[i][j - 1] == 1) res-=2;
                if (i > 0 && grid[i - 1][j] == 1) res-=2;
            }
        }
        return res;
    }
};
