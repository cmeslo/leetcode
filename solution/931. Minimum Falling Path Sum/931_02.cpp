class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = matrix[i][j];
                matrix[i][j] = INT_MAX;
                for (int k = max(0, j - 1); k <= min(n - 1, j + 1); ++k)
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][k] + val);
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
