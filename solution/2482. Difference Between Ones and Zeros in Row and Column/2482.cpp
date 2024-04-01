class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> onesRow(m), onesCol(n);
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    ++onesRow[i], ++onesCol[j];
        
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = 2*onesRow[i] + 2*onesCol[j] - m - n;
            }
        }
        return res;
    }
};


// diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
//            = onesRowi + onesColj - (m - onesRowi) - (n - onesColj)
//            = 2*onesRowi + 2*onesColj - m - n
