class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int res = 0;
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                res += (n - j);
                i--;
            } else {
                j++;
            }
        }
        
        return res;
    }
};

// [4,  3, 2,-1]
// [3,  2, 1,-1]
// [1,  1,-1,-2]
// [-1,-1,-2,-3]
