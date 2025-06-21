class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> row_min(m, 1e5 + 1), col_max(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                col_max[j] = max(col_max[j], matrix[i][j]);
                row_min[i] = min(row_min[i], matrix[i][j]);
            }
        }
        
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (col_max[j] == row_min[i])
                    res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
