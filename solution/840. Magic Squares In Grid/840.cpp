class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int target = 0;
        for (int i = 1; i <= 9; ++i)
            target |= (1 << i);
        
        int res = 0;
        for (int i = 0; i + 3 <= m; ++i) {
            for (int j = 0; j + 3 <= n; ++j) {
                // check 1 to 9
                int mask = 0;
                for (int y = i; y < i + 3; ++y) {
                    for (int x = j; x < j + 3; ++x) {
                        mask |= (1 << grid[y][x]);
                    }
                }
                if (mask != target) continue;
                
                // check sum of each row
                int same = true;
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                for (int y = i + 1; y < i + 3 && same; ++y) {
                    if (grid[y][j] + grid[y][j + 1] + grid[y][j + 2] != sum)
                        same = false;
                }
                // check sum of each col
                for (int x = j; x < j + 3 && same; ++x) {
                    if (grid[i][x] + grid[i + 1][x] + grid[i + 2][x] != sum)
                        same = false;
                }
                // check sum of diagonals
                same &= grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == sum && grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] == sum;
                res += same;
            }
        }
        return res;
    }
};
