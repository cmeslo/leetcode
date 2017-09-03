class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int rowLen = grid.size();
        int colLen = grid[0].size();
        
        for (int i = 0; i < rowLen; ++i) {
            for (int j = 0; j < colLen; ++j) {
                if (grid[i][j] == 1) res += sidesCount(grid, i, j);
            }
        }
        return res;
    }
    
    int sidesCount(vector<vector<int>>& grid, int row, int col) {
        int res = 0;
        int rowLen = grid.size();
        int colLen = grid[0].size();

        if (col - 1 < 0 || grid[row][col - 1] == 0) res++;
        if (row - 1 < 0 || grid[row - 1][col] == 0) res++;
        if (col + 1 > colLen - 1 || grid[row][col + 1] == 0) res++;
        if (row + 1 > rowLen - 1 || grid[row + 1][col] == 0) res++;
        
        return res;
    }
};
